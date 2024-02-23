# C++20 - Parsing ISO8601 Date and Time

In this code generation task, the objective is to create a C++20 program capable of parsing [ISO8601](https://en.wikipedia.org/wiki/ISO_8601) date and time strings, including the UTC offset.

## Problem Statement

ISO8601 is an international standard for representing dates and times in a human and machine-readable format. This task requires code generation in a C++20 conformant program that parses ISO8601 date and time strings, including the optional UTC offset. It must extract the individual components such as year, month, day, hour, minut, second, and UTC offset.


## Requirements

1. **Parsing ISO8601 Strings**: Implement a parser using `<regex>` which allows for missing components. The parser should handle the various formats allowed by the ISO8601 specification, including but not limited to:
 * Date only (YYY-MM-DD)
 * Date and time with optional milliseconds (YYYY-MM-DDTHH:MM:SS.SSS)
 * Date and time with UTC offset (YYYY-MM-DDTHH:MM:SS±HH:MM or YYYY-MM-DDTHH:MM:SSZ)
1. **Limitations**: The generated solution cannot using the `<chrono>` library, or the `std::get_time` method declared in the `<iomanip>` library.
1. **Component Extraction**: Extract the following components from each parsed ISO8601 string:
 * Year
 * Month
 * Day
 * Hour
 * Minute
 * Second
 * UTC Offset (if present)
1. **Output Format**: Display the extracted components of each parsed ISO8601 string in a clear and organised manner.
 * Any missing elements (that are valid to be missing), are assumed to have the value of zero.
1. **Invocation**: The program should take one string (surrounded by double quotes `"` as an argument passed on the command line.
 * Providing no argument is an error.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Implement robust error handling that gracefully handles invalid or malformed ISO8601 strings. Provide informative error messages to assist the user with debugging. Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the except

## Sample Usage

```bash
$ ./iso8601_parse "202220219T160000Z"
Year: 2022
Month: 2
Day: 19
Hour: 16
Minute: 0
Second: 0
UTC Offset: +00:00

$ ./iso8601_parse "2021-11-19T17:00:00+03:0"
Year: 2021
Month: 11
Day: 19
Hour: 17
Minute: 0
Second: 0
UTC Offset: +03:00

$ ./iso8601_parse "2024-02-19"
Year: 2024
Month: 2
Day: 19
Hour: 0
Minute: 0
Second: 0
UTC Offset: +00.00

```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries, or the `<chrono>` or `<iommanip>` headers.
* Ensure the program is robust and can handle various edge cases, such as malformed or incomplete ISO8601 strings.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


