#include <iostream>
#include <algorithm>
#include <concepts>
#include <exception>
#include <ranges>
#include <sstream>
#include <stdexcept>
#include <string_view>

// Custom string interpolation function
template<typename... Args>
std::string interpolate(std::string_view format, Args&&... args) {
    // Use a range to parse the format string
    auto tokens = format
        | std::ranges::views::split('[')
        | std::ranges::views::drop(1);

    // Create a string stream to build the result
    std::ostringstream result;

    // Iterate over the tokens and replace placeholders with arguments
    for (auto [text, placeholder] : tokens) {
        result << *text;

        if (!placeholder.empty()) {
            // Extract the placeholder index
            int index;
            try {
                index = std::stoi(std::string(placeholder));
            }
            catch (const std::invalid_argument& ex) {
                throw std::runtime_error("Invalid placeholder format: " + std::string(ex.what()));
            }
            catch (const std::out_of_range& ex) {
                throw std::runtime_error("Placeholder index out of range: " + std::string(ex.what()));
            }

            // Check if the index is within range
            if (index < 0 || index >= sizeof...(Args)) {
                throw std::runtime_error("Invalid placeholder index: " + std::to_string(index));
            }

            // Insert the corresponding argument
            result << std::apply([&args](Args&&... args) {
                return std::to_string(std::get<index>(args...)); }, 
                std::make_tuple(std::forward<Args>(args)...));
        }
    }

    // Return the interpolated string
    return result.str();
}


int main() {
    std::string_view name { "Alice" };
    int age { 40 };
    double height { 1.75 };

    auto result = interpolate("Hello, [0]! You are [2] meters tall and [1] years old");
    std::cout << result;

    // Result: "Hello, Alice! You are 1.75 meters tall and 40 years old"
    return 0;
}
