# Custom String Interpolation

Generate a custom string interpolation function that allows users to create formatted strings using a simplified syntax. The function must use the capabilities of C++20 ranges and `string_view` to parse format strings, identify placeholders, and replace them with the corresponding values. The implementation only needs to work in a single-threaded environment.

## Requirements

1. **Format String Syntax**: Use a simplified syntax for formatting strings. Placeholders should be denoted by square brackets `[]` and must contain an index to specify the argument position. See the example section below.
1. **Argument Handling**: Support inserting values of various types into the placeholders. The function must automatically convert the values to their string representations.
 * Consider using `concepts` to ensure that the parameters can be converted to a string representation.
1. **Range-based Parsing**: Use C++20 ranges to parse the format string. Use range adaptors and algorithms to extract placeholders and replace them with their formatted values.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
 * Deal with scenarios like missing placeholders, or out of bounds indices.
1. **Performance**: Use `string_view` to minimise string copies and allocationns.

## Examples

```cpp
// TODO: Add required headers

// TODO: implement the interpolate function

int main() {
    std::string_view name { "Alice" };
    int age { 40 };
    double height { 1.75 };

    auto result = interpolate("Hello, [0]! You are [1] years old and are [2] meters tall");
    std::cout << result;

    // Result: "Hello, Alice! You are 40 years old and are 1.75 meters tall"
    return 0;
}
```

## Notes

* Consider using parameter packs to pass arguments to `interpolate` function.
* Use `std::to_string` or `std::ostringstream` for converting arguments to their string representations.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



