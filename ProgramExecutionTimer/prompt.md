# C++20 - Program Execution Timer

Accurate program execution timing is essential for optimising software performance. This task requests the generation of a utility written in modern C++20 that automates the process of timing timing program executions, and giving useful feedback to users.

## Problem Statement

Manually measuring program execution times can be tedious and also prone to errors. To simplify this process, we need a utility that executes multiple programs with different arguments and reports their execution times.

## Requirements

1. **Program Timing**: 
 * Create a utility program capable of executing programs with provided arguments.
 * Measure the execution time of each program execution. 
 * Clearly report execution times, including program names and arguments passed.
1. **Input/Output Format**
 * Use single quotes to enclose each program and it's arguments.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: 
 * Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
 * Handle cases where programs or arguments are not provided correctly.
 * Handle and reject cases where the program fails to fully execute.

## Examples

```bash
$ ./time 'prog1 foo bar' 'prog2 12 "spam"'
prog1 foo bar: 12ms
prog2 "spam": 23ms

$ ./time 'program' 'another_program a1 a2'
program: 5ms
another_program a1 a2: 18ms
```

## Notes

* Use `<chrono>` standard library. And any other standard C++20 libraries. Do not use external libraries.
* Deal with cases where the arguments may need to include single quotes. For example, by escaping them, or using `''` to represent `'` being passed to the program being timed.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


