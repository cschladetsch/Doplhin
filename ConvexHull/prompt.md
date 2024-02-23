# C++20 - Calculate the Convex Hull of a set of 2D Points

## Problem Statement

Generate a C++20 program that calculates the *convex hull* of a set of 2D points provided via stdin. The program must output the sequence of points that specify the convex hull (defined below) in counter-clockwise order to stdout.

### Convex Hull Definition

The convex hull of a collection of points in a plane is the smallest convex polygon that encloses all the given points.

### Algorithm Guidance - Graham Scan

The Graham Scan algorithm is an efficient method for computing the convex hull, working in `O(n log(n))` time. It involves the following steps:

1. **Find the Pivot**: Select  the point with the lowest y-coordinate as the starting pivot. If there's a tie, the point with the lower x-coordinate is chosen.
1. **Sort Points**: Sort the remaining points based on their polar angle with respect to the pivot, from the smallest to the largest angle. The sorting facilitates the scanning process by arranging points in a manner that allows for easy determination of the convex hull.
1. **Scan**: Use a _stack_ data structure to maintain the potential points in the hull. For each sorted point, while the turn formed with the last two points in the stack is not counter clockwise, remove the second-to-last point. This process ensures that only points forming the outer boundary remain.
1. **Result**: The stack will then contain the points of the convex hull in counter clockwise order.

## Requirements

1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Input**: Should be read from standard input (stdin).
1. **Output**: Should be written to standard out (stdout).
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception. All errors are written to the standard output stream (stderr). Errors can include Edge cases as shown next, or malformed input.
1. **Edge Cases**: Should be detected and delt with gracefully, such as degenerate cases of one or two points, or a set of colinear points, etc.

## Example

```bash
$ echo -e "0 0\n1 2\n3 1\n4 3\n\n5 0\n7 2\n9 1" | ./convex_hull
0 0 
5 0 
9 1
7 2
4 3
1 2

$ echo -e "1 1\n2 3\n\3 2\n4 4\n5 1\n6 3\n" | ./convex_hull
1 1
5 1
6 3
4 4
2 3

$ echo "foo" | ./convex_hull
Error: "foo" is not an integer.
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



