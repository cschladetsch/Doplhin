# Basic Calculator

Generate a basic calculator using modern C++20. Take an expression from the command line and print the resultant evaluation.

## Requirements

1. **Operations**: Support addition (+), subtraction (-), multiplication (\*) and division (/).
1. **Data Types**: Support doubles. Output all results with 5 significant digits.
1. **Command Line Arguments**: Take one argument, as a mathematical expression using numbers and supported operations, surrounded by double quotes (").
1. **Parsing**: Accept mathematical expressions as command-line arguments.
1. **Order of Evaluation**: Follow standard mathematical rules for evaluation order (PEMDAS):
 * Parenthesised expressions.
 * Multiplication and Division.
 * Addition and Subtraction.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
 * Trap division by zero and report it.
 * Trap invalid input expressions.
1. Only support positive numbers in input expression.

## Structure

* Parse command-line arguments to extract the expression. 
* Evaluate the expression using the parser while respecting the order of operations.
 * Consider the use of a Stack and/or Abstract Syntax Tree (AST). 
* Display the result to standard output stream, and/or and error message written to standard error stream.

## Examples

```bash
$ ./calc "3.14"
3.1400
$ ./calc "1 + 3*4"
13.000
$ ./calc "(1 + 3)*4"
16.000
$ ./calc "3*4+7/2"
14.500
$ ./calc "asd"
Error: "asd" is not a valid expression
$ ./calc "1*2+"
Error: "1*2+" is not a valid expression
$ ./calc "1/0"
Error: Division by zero
```

## Notes

* Ensure parentheses are balanced in the input expression.
* Only support the required operations of addition, subtraction, multiplication and division.
* Division by zero will result in an error message written to `stderr` stream.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* It is not valid to throw exceptions from the `main` function.


