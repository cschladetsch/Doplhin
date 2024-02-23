# File Regex Replace

This task is to generate C++20 code to process a text file by searching occurrences of a specified regular expression pattern and replacing them with a provided term.

## Requirements

1. **Arguments**: The program takes three arguments:
 * The name of the file to process.
 * The regular expression, surrounded by double-quotes.
 * The replacement term, also surrounded by double-quotes.
1. **File Processing**: Open and read the specified file, handling any errors that may occur during any I/O operations.
1. **Search and Replace**: 
 * Use the provided regular expression pattern to search for matches within the file content.
 * The regular expression is of the form supported by the C++20 `<regex>` library.
 * Replace all occurrences of the matched pattern with the provided replacement term.
1. **Output**: Write the modified content to standard output (stdout), displaying the replaced content.
1. **Error Handling**: 
 * Gracefully handle errors related to file IO operations. Use exceptions for this.
 * Validate the provided regular expression term and handle any syntax errors.
 * Notify the user of any issues encountered during program execution, by writing informative error messages to standard error stream (stderr).
1. **Efficiency**:
 * Use efficient means to read the file contents.
 * Optimise the program to handle large files with little memory overhead.

## Samples

```bash
$ cat input.txt
foo spam foo
$ ./regex_replace input.txt "\bfoo\b" "bar"
bar spam bar
```

## Notes
* Ensure the program adheres to modern C++20 standards.
* Provide clear and concise user documentation in the form of inline comments that focus on the "why" and not the "how" or the "what".
* Encourage code reuse and maintainability through modular design and encapsulation of functionality.
* Consider using `<string_view>` to avoid unnecessary copying.
* Remember that both the regex and replacement term are surrounded by double quotes `"`.
