#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <string_view>
#include <stdexcept>

// Custom string interpolation function.
template <typename... Args>
std::string interpolate(std::string_view format_string, Args... args) {
    // Regex to match placeholders in the format string.
    const std::regex placeholder_regex{ R"(\[(\d+)\])" };

    // Function to replace placeholders with formatted arguments.
    std::string result;
    auto format_begin = format_string.begin();
    auto format_end = format_string.end();
    std::regex_iterator<std::string_view::iterator> iter{ format_begin, format_end, placeholder_regex };
    std::regex_iterator<std::string_view::iterator> end;

    size_t last_pos = 0;
    for (; iter != end; ++iter) {
        // Append the text before the match
        result.append(format_begin + last_pos, format_begin + iter->position());

        // Get the index from the match
        size_t index = std::stoi((*iter)[1]);

        // Check if the index is valid
        if (index >= sizeof...(args)) {
            throw std::out_of_range("Placeholder index out of range in interpolate()");
        }

        // Append the corresponding argument
        std::stringstream ss;
        ((void)(ss << std::get<index>(std::tuple<Args...>{args...})), result.append(ss.str()));

        // Update last position
        last_pos = iter->position() + iter->length();
    }

    // Append the remaining text
    result.append(format_begin + last_pos, format_end);

    return result;
}

int main() {
    try {
        std::string_view name{ "Alice" };
        int age{ 40 };
        double height{ 1.75 };

        auto result = interpolate("Hello, [0]! You are [2] meters tall and [1] years old.", name, age, height);
        std::cout << result << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Interpolation error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
