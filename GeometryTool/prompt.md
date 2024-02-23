# C++20 - Geometry Tool

This tool is used to calculate characteristics of different geometrical shapes.

## Problem Statement

Generate a C++20 program that performs various geometric calculations in two dimensions on different shapes. The program should support operations such as calculating the area, perimeter, and other relevant properties of shapes like squares, rectangles, circles, triangles, and polygons.

## Requirements

1. **Geometry Calculations**: Implement functions to calculate the area, perimeter (or in the case of circles, circumference) of the following shapes. Each is listed with the required parameters:
 * **Square**. The length of the sides. Example: "Square 4".
 * **Rectangle**. The length of each side. Example: "Rectangle 4 5".
 * **Triangle**. The length of each side. Example: "Triangle 3 4 5".
 * **Circle**. The radius of the circle. Example: "Circle 15".
 * **Polygon**. The number of edges, and the length of each edge. Example: "Polygon 12 3".
 * The shape descriptor is not case sensitive.
1. **Accuracy**: All internal calculations use single-precision floating point numbers. All output uses at most 2 decimal places.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception. Error messages are written to standard error (stderr).
1. **Input**: Is read from standard input (stdin).
1. **Output**: Is written to standard output (stdout). Use fixed 2-decimal output numbers.
1. **Modularity**: The code should be organised to add support for other geometric shapes.
1. **Robustness**: Design the code to be robust against various edge cases and corner scenarios. Handle boundary conditions, extreme values, and unexpected inputs gracefully. For example:
  * Negative length values for squares, triangles, etc.
  * Incorrect number of parameters given the Shape type.
  * Negative circle radii.


## Examples

### Calculate Area and Perimeter of a Square

```bash
$ echo "Square 5.0" | ./geometry_tool
Area: 25.00
Perimeter: 20.00
```

### Calculate Area and Circumference of a Circle

```bash
$ echo "Circle 3.0" | ./geometry_tool
Area: 28.27
Circumference: 18.85
```

### Calculate Area and Perimeter of a Polygon

```bash
$ echo "Polygon 6 4.0" | ./geometry_tool
Area: 41.57
Perimeter: 24.00
```

### Handle Bad input

```bash
echo "Triangle 3 4" | ./geometry_tool
Error: Invalid shape given.
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.

