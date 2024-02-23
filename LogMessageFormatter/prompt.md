# C++20 - Generate a Class to Generate Formatted Log Messages

## Objective

Generate a program written in modern C++20. This program contains a class called `LogMessageFormatter` that uses `std::format` to generate a timestamped log message that includes the log level, a timestamp, a log message identifier, and a user-provided message.

The format should facilitate parsing by both humans and other programs.


## Log Messsage Format

The format of the log message must include the following data:

* **Log Level**: One of INFO, WARNING, ERROR
* **Timestamp**: Specified as an [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601) formatted datetime string.
* **Log Message Id**: A unique, monotonically increasing value of the form "MSG00000001". Specifically:
 * The Id starts with the prefix "MSG".
 * Followed by 8 digits with leading zeroes.
 * Each log message has a unique Id.
 * The number increases monotonically. That is, each successive log message Id references a number that is greater than the previous log message.
* **User Message**: The user is able to pass a custom message that will be appended to the entire log message.

## Requirements

* **LogMessenger class**: Create a class called `LogMessenger` that captures all of the data specified above, including the creation of Log Message Id.
* **Performance**: The log message generation must be efficient and clear, making use of `std::format`s compile-time checks where possible.
* Use `std::format` to handle the string formatting and creation. The format string must be constructed to accommodate the log level, timestamp, message identifier, and user message.
* **Method Creation**: The generated class must include a method with the signature `std::string createLogMessage(Level level, const std::string_view& message)` that takes the log level as an enumeration value, a custom user log message string, and returns the formatted log message.
* The timestamp should be created using the `std::chrono` library and should reflect the current system time in UTC according to the [ISO 8601 standard](https://en.wikipedia.org/wiki/ISO_8601).
* The message identifier starts at 'MSG00000001' and increments by 1 for each new generated message.
* Demonstrate the program with a `main` function that creates a few log messages with appropriate and different arguments. Write results to `stdout`.

## Sample Output

```
2024-02-14T13:55:26+11:00 [INFO] MSG00000001 Application Started
2024-02-14T13:55:26+11:00 [ERROR] MSG00000002 Failed to open database connection
2024-02-14T13:55:26+11:00 [INFO] MSG00000003 Application Ends
```

## Notes

* Ensure the generated code is well-commented, focusing on comments that explain 'why' and not 'what'.
* Add comments around the use of `std::format` and other C++20 features used.
* Use type constraints and `static_assert` as required.
* Provide examples of how the generated class is used, including sample driver code in `main` as well as the produced output written to `stdout`.
* All errors are trapped locally and re-thrown to the caller, after adding extra local contextual information.

## Bonus

* Add a method to the `LogMessenger` class that takes a variable number of arguments, and uses those to produce the user-defined message.
* Use constraints to ensure compile-time correctness.


