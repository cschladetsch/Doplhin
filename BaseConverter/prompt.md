# Base Converter

Generate a modern C++20 program that converts a number from any [base format](#numbers_in_base_10) up to base Z (36) to its decimal equivalent.

## Requirements

1. **Input Handling**: Accept the number to convert and base format as command-line arguments.
1. **Base Range**: Support conversion from base 2 to base Z (36). The bases and number format are described [below](#numbers_in_base_10).
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. **Case Sensitivity**: Letters are not case sensitive. So, 'a' is equivalent to 'A'.

## Approach

1. Accept the number and its base format from the command line.
1. Validate the input and ensure it conforms to the specified base format.
1. Convert the input number from the given base format to decimal (base 10) format.
1. Write the result to standard output (`stdout`).

## Numbers in Base 10

| Base Z (36) | Decimal |
|-------|--------|
| 0 | 0 |
| 1 | 1 |
| 2 | 2 |
| ... | ... |
| A | 10 |
| B | 11 |
| ... | ... |
| Y | 34 |
| Z | 35 |

## Examples

```bash
$ ./base_converter 1z7 36
2563
$ ./base_converter 1011 2
11
$ ./base_converter 1A3 16
419
$ ./base_converter 123
Usage: ./base_converter <number> <base>
$ ./base_converter 1234 37
Base must be between 2 and 36
```

## Notes

* The input number can contain digits 0-9 and letters A-Z representing numbers from 0 to 35 in decimal.
* Ensure proper handling of invalid input cases, such as invalid characters in the input number (given the base range), or an invalid base.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.

