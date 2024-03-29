#include <string>
#include <string_view>
#include <type_traits>
#include <exception>

// Helper function to ensure type compatibility and conversion between different string representations
template <typename T>
consteval auto to_string(T&& str) {
    if constexpr (std::is_same_v<T, std::string>) {
        return str;
    } else if constexpr (std::is_same_v<T, std::string_view>) {
        return std::string(str);
    } else if constexpr (std::is_same_v<T, const char*>) {
        return std::string(str);
    } else {
        return "";//throw;// std::runtime_error("Invalid string type");
    }
}

//// Compile-time string concatenation using variadic templates
//template <typename... Args>
//consteval auto concat(Args&&... args) {
//    std::string result;
//    (result += to_string(std::forward<Args>(args)))...;
//    return result;
//}

// Compile-time whitespace trimming functions for front and back of strings
consteval auto trim_front(std::string_view str) {
    str.remove_prefix(std::min(str.find_first_not_of(" "), str.size()));
    return str;
}

consteval auto trim_back(std::string_view str) {
    str.remove_suffix(std::min(str.find_last_not_of(" ") + 1, str.size()));
    return str;
}

//// Helper function for compile-time string equality comparison
//template <typename T1, typename T2>
//consteval auto strings_equal(T1&& str1, T2&& str2) {
//    return to_string(str1) == to_string(str2);
//}
constexpr bool strings_equal(char const * a, char const * b) {
    return std::string_view(a)==b;
}
// Example usage:

int main() {
    try {
        // Concatenation
        //constexpr auto hello = concat("Hello", ", ", "World");
        //static_assert(strings_equal(hello, "Hello, World"), "Concatenation failed");

        // Trimming
        constexpr auto hello1 = trim_front("   Hello");
        //static_assert(strings_equal(hello, "Hello"), "Front trimming failed");

        constexpr auto hello2 = trim_back("World    ");
        static_assert(strings_equal(hello2, "World"), "Back trimming failed");

    } catch (const std::exception& e) {
        // Handle error and provide context
        //throw std::runtime_error("Compile-time string manipulation error: " + std::string(e.what()));
    }

    return 0;
}
