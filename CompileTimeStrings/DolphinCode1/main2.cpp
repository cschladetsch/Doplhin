#include <string>
#include <string_view>
#include <exception>

namespace compile_time_strings {

// Exception type for errors in compile-time string operations.
class CompileTimeStringError : public std::exception {
public:
    CompileTimeStringError(const char* message) : std::exception(message) {}
    const char* what() const noexcept override { return std::exception::what(); }
};

// Checks if two strings are equal at compile time.
template <typename Str1, typename Str2>
constexpr bool strings_equal(const Str1& str1, const Str2& str2) {
    return std::string_view(str1) == std::string_view(str2);
}

// Concatenates multiple strings at compile time.
template <typename... Args>
consteval auto concat(const Args&... args) {
    if constexpr (sizeof...(args) == 0) {
        throw CompileTimeStringError("Cannot concatenate empty string.");
    } else {
        return (args + ...);
    }
}

// Trims whitespace from the front of a string at compile time.
template <typename Str>
consteval auto trim_front(const Str& str) {
    // Find the first non-whitespace character.
    const auto first = str.find_first_not_of(" \t\n\v\f\r");
    if constexpr (first == std::string::npos) {
        return "";
    } else {
        return str.substr(first);
    }
}

// Trims whitespace from the back of a string at compile time.
template <typename Str>
consteval auto trim_back(const Str& str) {
    // Find the last non-whitespace character.
    const auto last = str.find_last_not_of(" \t\n\v\f\r");
    if constexpr (last == std::string::npos) {
        return "";
    } else {
        return str.substr(0, last + 1);
    }
}

int main() {
    // concatenation
    constexpr auto hello = concat("Hello", ", ", "World");
    static_assert(strings_equal(hello, "Hello, World");

    // trimming
    constexpr auto hello2 = trim_front("   Hello");
    static_assert(strings_equal(hello, "Hello");

    constexpr auto hello3 = trim_back("World    ");
    static_assert(strings_equal(hello, "World");

}

