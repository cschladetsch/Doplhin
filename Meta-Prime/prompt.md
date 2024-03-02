# C++20 - Compile-time Primes

Generate code that uses meta-programming technqiues available to C++20 to define a concept called `Prime` to check if a given positive integer is actually a prime number.

This must all all occur at compile-time.

## Requirements

1. **Define a Concept for a Prime Number**: Create a concept called `Prime`. This concept must ensuir that a gien number is greater than 1, and that the modulus of the number is itself or 1. 
 * A prime number is divisible by itself and 1. 1 is not a prime number.
 * It is crucial that the test is performed entirely in compile-time.
 * Provide all concepts, equally distributed as if they were runtime functions.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.


## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* Use `static\_assert` and concepts to ensure compile-time efficiency and useful error messages.



