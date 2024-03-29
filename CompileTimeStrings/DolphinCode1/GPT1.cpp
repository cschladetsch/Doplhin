#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Concept to check if a type is a string type
template<typename T>
concept StringType = requires(T t) {
    { std::declval<T>().c_str() } -> const char*; // Check for c_str() method
};

// Concatenate strings at compile time
template<StringType... Strings>
consteval std::string concat(Strings... strings) {
    return (strings + ...);
}

// Split a string at compile time
template<StringType StringType>
consteval auto split(StringType str, const char* delimiter) {
    std::vector<std::string_view> result;
    std::string_view sv(str);
    size_t pos = 0;
    while (pos < sv.length()) {
        auto found = sv.find(delimiter, pos);
        if (found == std::string_view::npos) {
            result.push_back(sv.substr(pos));
            break;
        }
        result.push_back(sv.substr(pos, found - pos));
        pos = found + strlen(delimiter);
    }
    return result;
}

// Trim leading and trailing whitespace at compile time
template<StringType StringType>
consteval auto trim(StringType str) {
    std::string_view sv(str);
    size_t start = sv.find_first_not_of(" \t\n\r");
    size_t end = sv.find_last_not_of(" \t\n\r");
    if (start == std::string_view::npos || end == std::string_view::npos) {
        return std::string("");
    }
    return std::string(sv.substr(start, end - start + 1));
}

// Find substring at compile time
template<StringType StringType>
consteval bool find(StringType str, const char* substr) {
    std::string_view sv(str);
    return sv.find(substr) != std::string_view::npos;
}

// Replace substring at compile time
template<StringType StringType>
consteval auto replace(StringType str, const char* old_substr, const char* new_substr) {
    std::string result(str);
    size_t pos = result.find(old_substr);
    if (pos != std::string::npos) {
        result.replace(pos, strlen(old_substr), new_substr);
    }
    return result;
}

// Convert string to uppercase at compile time
template<StringType StringType>
consteval auto to_uppercase(StringType str) {
    std::string result(str);
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

int main() {
    // Example usage
    constexpr auto hello = concat("Hello", ", ", "World!");
    static_assert(hello == "Hello, World!");

    constexpr auto words = split("Hello, World!", ", ");
    static_assert(words.size() == 2 && words[0] == "Hello" && words[1] == "World!");

    constexpr auto trimmed = trim(" \t  Hello  \n");
    static_assert(trimmed == "Hello");

    constexpr bool contains = find("Hello, World!", "llo");
    static_assert(contains);

    constexpr auto replaced = replace("Hello, World!", "World", "Universe");
    static_assert(replaced == "Hello, Universe!");

    constexpr auto uppercase = to_uppercase("Hello, World!");
    static_assert(uppercase == "HELLO, WORLD!");

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
