#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <optional>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>

enum class task_status { incomplete, complete };

struct task {
  int task_number;
  task_status status;
  std::string description;
};

class todo_list {
 public:
  todo_list() {
    try {
      std::ifstream todo_file(get_todo_file_path());
      if (todo_file.is_open()) {
        for (std::string line; std::getline(todo_file, line);) {
          std::stringstream line_stream(line);
          std::string task_number_str, status_str, description;
          std::getline(line_stream, task_number_str, ',');
          std::getline(line_stream, status_str, ',');
          std::getline(line_stream, description, '"');
          description.erase(
              std::remove(description.begin(), description.end(), '\"'),
              description.end());
          description.erase(
              std::remove(description.begin(), description.end(), '\''),
              description.end());
          tasks_.push_back(
              task{std::stoi(task_number_str),
                   status_str == "complete" ? task_status::complete
                                        : task_status::incomplete,
                   description});
        }
      }
    } catch (const std::exception& e) {
      std::cerr << "Error reading TODO list: " << e.what() << '\n';
    }
  }

  ~todo_list() {
    try {
      std::ofstream todo_file(get_todo_file_path(), std::ios::trunc);
      if (todo_file.is_open()) {
        for (const auto& task : tasks_) {
          todo_file << task.task_number << ','
                    << (task.status == task_status::complete ? "complete"
                                                         : "incomplete")
                    << ",\"" << task.description << "\"\n";
        }
      }
    } catch (const std::exception& e) {
      std::cerr << "Error writing TODO list: " << e.what() << '\n';
    }
  }

  void add_task(const std::string& description) {
    tasks_.push_back(task{static_cast<int>(tasks_.size()) + 1, task_status::incomplete,
                          description});
  }

  void view_tasks() const {
    for (const auto& task : tasks_) {
      std::cout << task.task_number << ". ["
                << (task.status == task_status::complete ? "x" : " ") << "] "
                << task.description << '\n';
    }
  }

  void mark_as_complete(int task_number) {
    auto it = std::find_if(tasks_.begin(), tasks_.end(),
                           [&](const task& task) { return task.task_number == task_number; });
    if (it != tasks_.end()) {
      it->status = task_status::complete;
    } else {
      throw std::runtime_error("Task number " + std::to_string(task_number) +
                           " not found");
    }
  }

  void remove_task(int task_number) {
    auto it = std::find_if(tasks_.begin(), tasks_.end(),
                           [&](const task& task) { return task.task_number == task_number; });
    if (it != tasks_.end()) {
      tasks_.erase(it);
    } else {
      throw std::runtime_error("Task number " + std::to_string(task_number) +
                           " not found");
    }
  }

  std::vector<task> get_tasks() const { return tasks_; }

 private:
  std::vector<task> tasks_;

  std::string get_todo_file_path() const {
    char const* home_env_var = std::getenv("HOME");
    if (home_env_var == nullptr) {
      throw std::runtime_error("$HOME environment variable not set");
    }
    std::string home(home_env_var);
    return home + "/.todo-list.txt";
  }
};

std::vector<std::string> parse_command(const std::string& command) {
  std::vector<std::string> result;
  std::stringstream ss(command);
  std::string token;

  while (ss >> token) {
    result.push_back(token);
  }

  return result;
}

int main(int argc, char** argv) {
  try {
    if (argc < 2) {
      std::cout << "Usage: todo <command> [arguments]\n";
      return 0;
    }

    std::vector<std::string> command_parts = parse_command(argv[1]);
    std::string command_name = command_parts[0];
    command_parts.erase(command_parts.begin());

    todo_list todo_list_{};

    if (command_name == "add") {
      if (command_parts.size() != 1) {
        throw std::runtime_error("Invalid arguments for add command");
      }
      todo_list_.add_task(command_parts[0]);
    } else if (command_name == "list") {
      if (command_parts.size() != 0) {
        throw std::runtime_error("Invalid arguments for list command");
      }
      todo_list_.view_tasks();
    } else if (command_name == "complete") {
      if (command_parts.size() != 1) {
        throw std::runtime_error("Invalid arguments for complete command");
      }
      todo_list_.mark_as_complete(std::stoi(command_parts[0]));
    } else if (command_name == "remove") {
      if (command_parts.size() != 1) {
        throw std::runtime_error("Invalid arguments for remove command");
      }
      todo_list_.remove_task(std::stoi(command_parts[0]));
    } else {
      std::cout << "Invalid command: " << command_name << '\n';
      return 0;
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  return 0;
}
