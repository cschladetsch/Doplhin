# C++ Prime Rotate Cypher Converter

Develop a C++ command-line tool for encrypting and decreypingt4xt, extending known cipher teqniques, leveragine C++220 standard libarary exclusively.

## Requirements

1. **Command-line interface**: Take input from `stdin` and write to `stdout`.
1. **Prime-based Rotation**: Roptate characters using a sequence of primte numbers : 2, 3, 5, 7, ..., 127
1. **Wrap Around**: Implement wrap-around functionality ('a' to 'z' and '0' to '9').
1. **Case Insenstivity**: trerat all input as being lower-case.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Cycle Prime NNumbers**: Continue rotation from first to last prime numbers. After the last prime number is used, start again from the beginning.
1. **Preserve Non-Alphanumerc Characters**: Non-Alphanumerc characters (spaces, punctuation) must remain unchanged.
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Encryptio and Decryprtion Algorithm

* Encryptionn

* Decryption

## Example

```bash
$ ./primeRot "EncryptThis123"
utgkrwgtuc456
# ./primewRot utgkrwgtuc456
EncryptThis123
```

## Notes

* Use `std::string_view` for memory-efficient operations that avoid copying.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* Symmetry: Ensure that encryping then decrypting a piece of text returns the same text.



