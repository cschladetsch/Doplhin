# C++20 - Scoped Timer

Assistance is needed to help developers pinpoint performance hotspots within code by measuring time taken to execute code blocks.

## Problem Statement

Timely execution of code is a priority in software development. Ther is a requirement for a system that developers can use to measure and later analyse the time spent on code block efficiency.

The required `ScopedTimer` class will address this by providing a straightforward mechanism that records time taken within a code block. It should then write the results to standard error (stderr).

## Requirements

1. **C++20 Standards**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Construction Parameters**: The class must take a string-like object as a parameter to name the timer instance for later reporting.
1. **Time Measurement**: The class must use the `<chrono>` library for timing measurements.
1. **Reporting**: The class must output the total time elapsed in milliseconds and the timer's name to stderr when the instance is destroyed.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Sample Usage

```cpp
void DatabaseLoad() {
  ScopedTimer timer("DatabaseLoadTimer");
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
  // ScopedTimer `timer` will write the duration of the execution of this code block to stderr when the function exits.
}

```

## Notes

* The `ScopedTimer` class should be precise yet have minimal impact on overall performance of the program.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.

