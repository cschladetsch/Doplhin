# C++20 - Write a parabola to stdout

Generate a `write_parabola` program that takes three arguments. These represent the corefficients of the quadratic equation \( ax^x + bx + c )\) and plots the points resultant graph on an 80x80 grid of ASCII characters.

## Problem Statement

Quadratic equations are fundamental in mathematics. A `write_parabola` program is to be produced using modern C++20 language, to provide a simple utility to visualise a quadratic equation by plotting it on a graph using ASCII graphics.

## Requirements

1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Command Line Arguments**: There are three command line arguments, each required, and each represented as a double literal:
 * \( a\): Coeffient of \( x^2\).
 * \( b\): Coeffient of \( x\).
 * \( c\): Constant offset.
1. **Output**:
 * Plot the equation on an 80x80 graph of ASCII characters, with `*` representing a point on the curve.
1. **Error Handling**: Handle input arguments in a separate function, throwing exceptions after adding extra contextual information.
1. **Graph Centering**:
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Examples

```bash
$ ./write_parabola 1 0 0 
# ...output...
$ ./write_parabola 2 3 4
# ...output...
$ ./write_parabola -2 1 -3
# ...output...
```

## Notes

* The program validates and converts command-line arguments to double-precision numbers.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* The graph is centered within the 80x80 representation to show the areas of greatest gradient changes.




