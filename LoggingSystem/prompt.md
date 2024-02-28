# C++20 - Logging System

Efficient logging is essential for debugging, monitoring, an analysing software behavior. The code generation task outlined here requires the development of a logging utility in modern C++20, using `std::source_location::current()` to provide contextual information such as file name, line number, and function name in log messages.

## Requirements

1. **Logging Mechanism**: Implement logging using variadic macros to handle messages with different numbers and types of arguments.
1. **Type Safety**: Ensure type safety with template arguments for loigging diffeerent data types. Handle both primitive and custom types.
1. **Severity Levels**: Define macros:
 * LOG\_INFO(...)
 * LOG\_WARNING(...)
 * LOG\_ERROR(...)
 * LOG\_VERBOSE(...)
1. **Message Formatting**: Enable messages to include additional variables in log messages, with the only requirement that a variable to be logged can be written to a `std::ostream` instance.
1. **Thread Safety**: Assume the application is single-threaded.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Examples

### Simple Logging

```cpp
void example(int c) { // asssume c is passed in with the value 42
  std::string str = "hello";
  float b = 3.14f;
  LOG_INFO("Values", a, b, c);
}
```

* Output:

```bash
[INFO] Values: a='hello', b=3.14, c=42. File=Test.cpp, Line=39, Func=example
```

### Error Logging

Log an error message with additional information using `LOG_ERROR` macro:

```cpp
void handleError(const std::string_view& errorMessage) {
    int errorCode = 404;
    LOG_ERROR("Failed", errorMessage, errorCode);
}
```

* Output:

```bash
[ERROR] Failed: errorMessage="File not found", errorCode=404, File=httpHandle.cpp, Line=89, Func=handleError
```

### Performance Metrics

```c++
void logPerformance(const std::string_view& action, double millis) {
  LOG_INFO("Performance", action, millis);
}
```

* Output:

```bash
[INFO] Performance: action="Data processing", duration=10.5. File=perf.cpp, Line=109, Func=logPerformance
```

## Notes

* Include context information, (file name, line number, function name) in log messages using `std::source_location::current()`.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



