# C++20 - Perfect Numbers

## Problem Statement

Generate a program that determines if a given number is `n` is a 'Perfect Number'. The program writes "yes" if it is a Perfect Number, else "no". 

### Perfect Numbers

A 'perfect number' is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. For instance, 6 has divisors 1, 2 and 3 (excluding itself), and 1 + 2 + 3 = 6, so 6 is a perfect number.

Rather, 12 has divisors 1, 2, 3, 4, 6. The sum of these numbers is 16. So 12 is not a perfect number.

## Requirements

1. **Input**: Read a positive integer that fits into the range of 2^32 from standard input (stdin).
1. **Output**: Write "yes" to standard output (stdout) if the number is a 'perfect number', else write "no". Do not include quotes and write to standard output.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception. Write all error messages to the standard error stream `stderr`.

## Examples

```bash
$ echo 28 | ./is_perfect 
yes
$ echo 12 | ./is_perfect 
no
$ echo "foo" | ./is_perfect 
Error: "foo" is not an integer.
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases, such as malformed input numbers.
* Prioritise code readability in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* Negative numbers cannot be 'perfect numbers'.
