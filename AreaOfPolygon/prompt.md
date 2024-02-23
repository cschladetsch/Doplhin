# C++20 - Area of a Regular Polygon

## Problem Statement

Given a number of sides N, and a length for each side L, calculate the regular convex polygon formed by those points.

## Requirements

1. **Precision**: Consider the mathematical precision and edge cases that might affect the calculation. Use double-precision floats (`double`s) for all internal calculations.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Structure**: Use functions, classes or structures as necessary to keep the code clean, maintainable, and modular.
1. **Input**: Take the number of sides and length of each side as a pair of floating-point numbers from standard input (stdin).
1. **Output**: Write the result as a single floating-point number to standard output (stdout). Used at most 2 decimal digits of precision for all outputs.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception. Write all error output to the standard error (stderr) output stream.

## Algorithm Guidance

The Formula to Calculate the Area (A) of a Regular Polygon is:
* A = (n/2) \* L \* R. 
* n is the number of sides in the polygon. 
* L is the length of one edge of the polygon.
* R is the radius of an inscribed circle. 
 * R = L/(2\*tan(π/n))

## Examples

```bash
$ echo -e "4 2" | ./calc_poly_area
8
$ echo -e "6 7" | ./calc_poly_area
16
$ echo -e "foo" | ./calc_poly_area
Error: "foo" is not a valid integer.
```

## Notes

* Be careful of numeric limits.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during argument parsing or execution.

