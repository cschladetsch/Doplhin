# Compile Time Strings

Generate a comprehensive compile-time string manipulation library using C++20.

## Requirements

1. **Compatibility**: Support different string representations (e.g. `std::string`, `std::string_view`, C-style strings) and ensure compatibility between them. 
1. **Type Safety**: Incorporate C++20 concepts to enforce type safety and provide meaningful error messages when invalid types are used.
1. **Compile-Time Operations**: Ensure all string manipulation functions are implemented using `consteval` functions and `constexpr` expressions to guarantee correct compile-time evaluation.
1. **Operations**: Provide the following string manipulation functionality:
 * String concatenation: `concat`. Takes a variable number of arguments.
 * String whitespace trimming (from front and back): `trim_front`, `trim_back`
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Examples

```cpp
// concatenation
constexpr auto hello = concat("Hello", ", ", "World");
static_assert(strings_equal(hello, "Hello, World");

// trimming
constexpr auto hello = trim_front("   Hello");
static_assert(strings_equal(hello, "Hello");

constexpr auto hello = trim_back("World    ");
static_assert(strings_equal(hello, "World");
```

## Notes

* std::strings\_equal is in <string_view> header.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



