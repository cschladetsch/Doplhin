# Number Histogram

Write a histogram of numbers read from standard input. Use C++20.

## Requirements

1. **Input**: Read integers separated by any whitespace from standard input until end of line (EOL). 
 * All integers will fit into `int` data type.
1. **Output**: Write a map of each number and its frequency. The output should display each input number along with a visual representation of the frequency of that number. See [Example](#example) for details
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: 
 * Use exceptions to deal with errors. 
 * When errors are caught, add local contextual extra information then rethrow the exception.
 * Trap when there is no input.

## Example

```bash
$ echo "1 2 4 2 1 4 2 4 2 3 4" | ./histogram
1: **
2: ***
3: *
4: ***
```

## Notes

* Ensure the input is parsed correctly and give useful error message otherwise.
* Consider using the `<ranges>` library.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



