# C++20 - ISBN Parser

Generate a C++20 program that parses and validates ISBN-13 numbers, designed for libraries, bookstores, and online reatil systems. 

## Requirements

1. **Input**: Is provided vi standard input `stdin` or `cin`. 
1. **Efficiency**: Use `string_view` to reduce copying data.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Standards Compliance**: Accurately parses and validates ISBN-13 components in alignment with international standards.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. **Assumes acccess to just a local test library**: The program doesn not have to know about every book every to have an ISBN assigned to it.

## Real-World Examples

### Valid

```bash
$ cat 9780747532743 | ./isbn-13

* Valid
* Book: Harry Potter and the Philosopher's Stone - Softcover
* Author: J.K. Rowling
* GS1 prefix: 978
* Registration Group Element: 0
* Regisrant Element: 545
* Check Digit: 1

```

## Notes

* Parsing Logic: Implement efficient and sufficient parsing that reports errors with context.
* Validation: The check digit calculation must follow the Modulo 10 system with alternating weights of 1 and 3, from left ot right.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



