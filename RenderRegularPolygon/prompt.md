# C++20 - Render Regular Polgon

Generate a program called 'render\_poly' that creates and draws a regular  polygon.

## Requirements

1. Assume a 80x80 output space, with the origin at 40,40.
1. **CommandLine Arguments**:
 * The arguments are not named on the command line. The are sequential.
 * num-sides: the number of sides of the polygon.
 * length: the length of each edge of tyhe polyon.
1. **Output**:
 * Written to `stdout`.
 * Use `*` to indicate a point on the edges of the polgon.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
 * This includes negative edges and negative edge lenghts.
1. Ensure that the polygon has the correct aspect ratio.

## Examples

```bash
$ ./render_poly 10 5
# ... output .. 
$ ./render_poly 4 4
# ... output .. 
```

## Notes

* Use basic gemetric pricniples to calculate the coordinates of each vertex of the polygon.
* Use [Breshenem Line Draw[(https://en.wikipedia.org/wiki/Bresenham%27s\_line\_algorithm) algorithm to draw the edges.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.

