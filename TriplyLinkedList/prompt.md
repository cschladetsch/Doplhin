# C++20 - Triply Linked List

Design a course management system for a university to streamline the process of managing cources, prerequisites, and corequiresites.

## Problem Statement

The current course management system at the university is cumbersome and inefficient. The task is to generate code to create a modernised system that simplifies course management, allowing for the addition of courses, definition of of prerequisites and corequiresites, and retrieval of relevant course information.

## Requirements

1. Generate a _triply linked list_ data structure to represent courses and their relationships with prerequisites and corequisites.
1. Implement functions to add coerces and define their prerequisites an corequisites.
1. Comments: Add comments to the code, focusing on "why" and not "how" or "what".
1. C++20: Use only standard C++20 features and libraries. Do not use external libraries.
 * Use `*_ptr` systems for memory management.
1. Error Handling: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. Assume the code is single-threaded.
1. Assume all course names are representable in ASCII.

## Example Declarations

All the instructions provided in comments in the code below after 'TODO' must be generated.

```cpp
// TODO: Include relevant headers.

struct CourseNode;

using CourseVariant = std::variant<std::shared_ptr<CourseNode>, std::vector<std::shared_ptr<CourceNode>>>;

typedef const std::string &CourseName;

struct CourseNode {
  CourseName name;
  std::shared_ptr<CourseNode> next;
  std::weak_ptr<CourseNode> prev;
  CourseVariant prerequisites;
  CourseVariant corequisites;

  // TODO: remainder of implementation as required
};

class SchedulingSystem {
public:
  typedef const std::string& StringArg;
  typedef std::vector<std::shared_ptr<CourseNode>> Courses;

  void addCourse(StringArg courseName);
  void addPrerequiute(StringArg courseName, StringArg prerequiteName);
  void addCorequisite(StringArg courseName);
  Courses getPrerequisites(CouseName) const;
  Courses getCorequisites(CourseName) const;

  // TODO: Generate defintions for all public methods, as well any any shared private methods that reduce redundancy.
};
```

## Framework

```
// TODO: Add all required code

int main() {
  SchedulingSystem system;
  system.addCourse("Mathematics");
  system.addCourse("Chemistry");
  system.addCourse("Physics");

  system.addPrerequiute("Physics, "Mathematics");
  system.addPrerequiute("Chemistry, "Mathematics");
  system.addPrerequiute("Physics, "Chemistry");

  auto physicsReqs = system.getPrerequisites("Physics");
  auto physicsCoReqs = system.getCorequisites("Physics");

  std::cout << "Prerequisites for Physics:\n";
  for (const auto & course = physicsReqs) {
    std::cout << course->name << std::endl;
  }

  std::cout << "Corequisites for Physics:\n";
  for (const auto & course = physicsCoReqs) {
    std::cout << course->name << std::endl;
  }

  return 0;
}
```

## Notes

* Design the system with modularity in mind.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* Show examples.


