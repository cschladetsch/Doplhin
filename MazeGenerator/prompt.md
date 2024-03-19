# Maze Generator

Generate a program using modern C++20 that generates mazes of various sizes.

## Requirements

1. **Use Prim's Algorithm**: As described [below](#prims_algorithm).
1. **Customisation**: Accept the dimensions (rows and columns) of the maze from the command line.
 * These must be in the range [5..20].
1. **Validity Checking**: Ensure the generated maze is actually solvable.
1. **Start- and End-Points**: Start at the top-left and end at the bottom-right.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
 * The only errors should occur are input parsing from the command line.
 * Anything else is a fault of the program itself and should be thrown as a `std::logical_error` exception and reported to the user.
 * All error messages are to be written to standard error stream `stderr`.
1. Ensure there is only one solution to the maze.
1. Ensure there are no loops in the maze.

## Prims Algorithm

1. Start with a grid full of walls.
1. Pick a cell, mark it as a part of the maze. Add the walls of the cell to the wall list.
1. While there are walls in the list:
 1. Pick a random wall from the list. If only one of the cells that the wall divides is visited, then:
  * Make the wall a passage and mark the unvisited cell as part of the maze.
  * Add the neighboring walls of the cell to the wall list.
 2. Remove the wall from the list.

## Approach

1. Accept maze dimenstions (rows and columns) from the command line as per [Requirements](#requirements).
1. Implement 'Prim's Algorithm' for maze generation.
1. Ensure the generated maze has a clear and unambiguous path from Start to End.
1. Show the result:
 * '#' for walls.
 * ' ' for paths.
 * 'S' for Start point.
 * 'E' for End point.
 * '.' for a point on the path from Start to End.
1. Show the path from the Start to the End through the maze using thet '.' symbol.

## Example

```bash
$ ./maze_generator 5 5 
S####
   ##
 #  #
 #  E
```
## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation. In that order.
* Provide clear and informative error messages in case of any issues encountered during execution.

