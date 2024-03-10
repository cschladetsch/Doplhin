# C++20 - Compile Time Perfect Numbers

Generate a program that uses the capabilities of C++20 to detetrmine if a given number is [perfect](#perfect-numbers) at compile time.

Do this at compile-time only, using C++20 `consexpr` and `if constexpr` constructs to determine the perfection of a provided integral value at compile-time.

## Perfect Numbers

In number theory, a perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. 

## Requirements

1. Implement a `constexpr` function named `isPerfect`, which returns true if and only if the given number is perfect, as defined above.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.

## Sample Usage

```cpp
static_assert(isPerfect(28)); // 1 + 2 + 4 + 7 + 14 = 28. 
```

## Notes

* Provide a complete program showing at least two perfect numbers.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.

