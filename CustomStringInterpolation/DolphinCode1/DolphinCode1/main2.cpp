#include <exception>
#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <string_view>

// Concept to ensure that an argument can be converted to a string representation.
template <typename T>
concept ToStringable = requires(T value) {
    { std::to_string(value) } -> std::convertible_to<std::string>;
};

// Custom string interpolation function.
template <typename... Args>
std::string interpolate(std::string_view format_string, Args... args) {
    // Regex to match placeholders in the format string.
    const std::regex placeholder_regex{ R"(\[(\d+)\])" };

    // Function to replace placeholders with formatted arguments.
    const auto replace_placeholder = [&args](const auto& match) -> std::string {
        const int index = std::stoi(match[1].str());

        // Check if the placeholder index is within bounds.
        if (index < 0 || index >= sizeof...(args)) {
            throw std::out_of_range("Placeholder index out of range in interpolate()");
        }

        // Get the argument corresponding to the placeholder index.
        const auto& arg = std::get<index>(std::tie(args...));

        // Convert the argument to a string and return it.
        return std::to_string(arg);
        };

    // Use ranges to process the format string and replace placeholders.
    std::string result;
    std::ranges::transform(
        std::ranges::subrange(std::sregex_iterator(format_string.begin(), format_string.end(), placeholder_regex),
            std::sregex_iterator()),
        std::back_inserter(result),
        replace_placeholder);

    return result;
}

// Exception class for interpolation errors.
class InterpolationError : public std::exception {
private:
    std::string message_;

public:
    InterpolationError(const std::string& message) : message_(message) {}

    const char* what() const noexcept override { return message_.c_str(); }
};

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