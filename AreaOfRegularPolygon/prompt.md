# C++20 - Area of a Regular Polygon

Generate a C++20-compliant program to computer the area of a regular polygon.

The program must take the number of edges, and the length of each edge, as program arguments passed to the `main` function.

The output is the area of the regular polygon provided.

## Requirements

1. **Write the output to `stdout`**: The output consists of a single number that is the area of the regular polygon described by the program's arguments.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception. Write error messages to the `stderr` stream. Errors can include:
 * Passing invalid input (i.e., passing a string "12" rather than a number 12)
1. **Input**:
 * The number of edges is the first argument. This is a positive integer.
 * The length of each edge is provided as a floating-point number. Assume that this number is valid for a single-precision floating-point C++ number.
1. **Precision**: Use doubles for all calculation, and write results using fixed 2 decimal places.
1. **Examples**: Provide at 3 reasonable examples of usage, including input and output.

## Provided Framework

When a comment is given starting with the word "TODO" it means that code must be generated at that location.

```cpp
// TODO: include all necessary headers

float calcRegularPolygonArea(int edges, float edgeLength); // TODO: implement this function

int main(int argc, char **argv) {
  // TODO: Read values from the command line (the number of edges, and the length of each edge)

  // TODO: Calculate the area of the regular polygon described by the two input arguments, and passed to the `calcRegularPolygonArea` function.
  
  // TODO: trap all input errors, including badly formed integers

  return 0;
}

```

## Sample Usage

```bash
$ ./calc_poly_area 4 4.5
20.25
$ ./calc_poly_area 13 9.8
1266.36
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


