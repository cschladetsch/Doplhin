# C++20 - Prime Number Estimation

## Problem Statement

Generate a C++20 program that, given an upper limit as a command0line argument, estimates the count of prime numbers below that number using Riemann's [prime-counting function](https://en.wikipedia.org/wiki/Prime-counting_function).


## Requirements

1. **Command-Line Arguments**: The program takes one argument, which is an unsigned integer given as the upper bound to the 'prime counting function'.
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception. This includes being unable to parse the command-line argument as an unsigned 32-bit integer.
1. **Algorithim**: 
 * Implement Riemann's prime-counting function algorithm to estimate the count of prime numbers below the given program argument.
 * Ensure efficiency and accuracy in the algorithm implementation, described below.

### Algorithm Descrtipion

* TODO

### Algorithm Testing

 1. Prime Number Check.
  * Iterate through each integer from 2 to the upper limit.
  * Check if each integer is prime using a test algorithm.
 1. Counting Prime Numbers.
  * Increment a counter for each prime number found.
 1. Output Result.
  * Write the final count of prime numbers to standard output (stdout).


## Sample Usage

```bash
$ ./prime_counter 1000000
78498
$ ./prime_counter 5000000
348513
$ ./prime_counter foo
Error: "foo" is not a positive integer
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



