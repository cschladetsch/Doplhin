# C++ Prime Rotate Cypher Converter

Develop a C++ command-line tool for encrypting and decreypingt4xt, extending known cipher techniques, leveraging C++220 standard library exclusively.

## Requirements

1. **Command-line interface**: Take input from `stdin` and write to `stdout`.
1. **Prime-based Rotation**: Rotate characters using a sequence of prime numbers : 2, 3, 5, 7, ..., 127
1. **Wrap Around**: Implement wrap-around functionality ('a' to 'z' and '0' to '9').
1. **Case Insensitivity**: Treat all input as being lower-case.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Cycle Prime Numbers**: Continue rotation from first to last prime numbers. After the last prime number is used, start again from the beginning.
1. **Preserve Non-Alphanumeric Characters**: Non-Alphanumeric characters (spaces, punctuation) must remain unchanged.
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Encryption and Decryption Algorithm

Start with a static sequence of all prime numbers in range [1..127]. Note that 1 is not a prime number.

* Encryption

1. Character Rotation. 
 * For each alphabetic and numeric number in the input, determine its position within a range of [0..25] for letters (a-z) or [0-9] for numbers.
 * Find the corresponding prime number based one the character's position in the text. That is, the first number has index 0, the next has 1, etc. It wraps around at the size of the primes provided. In this case, it means the corresponding prime has indexed to the number of primes in range [1..127]. Note that 1 is not a prime number.\
 * Apply the prime rotation using `(index + prime) % 26` for letters and `(value + prime) % 10` for numbers.
 * Convert the result to a character, ensuring all alphabetic output is lowercase.
2. Output construction. Assemble the encrypted string, maintaining the position of all non-alphanumeric characters.

* Decryption
1. Use the same prime sequence. The decryption process uses the same sequence of prime numbers as used in the encryption process.
1. Reverse Character Rotation. 
 * Similar to the encryption process, determine the character's original position. For decryption. subtract the prime number instead.: `(index - prime + 26 % 26` for letters and `(value- prime + 10) % 10` for numbers, ensuring proper wrap around.

## Example

```bash
$ ./primeRot "EncryptThis123"
utgkrwgtuc456
# ./primeRot utgkrwgtuc456
EncryptThis123
```

## Notes

* Use `std::string_view` for memory-efficient operations that avoid copying.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* Symmetry: Ensure that encrypting then decrypting a piece of text returns the same text.



