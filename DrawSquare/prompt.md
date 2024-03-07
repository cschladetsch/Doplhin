# C++20 - Draw Square to a Text File

## Problem Statement

Create a C++ program to render a square on a grid and save it to a file. The program should offer a simple interface (without naming arguments), for defining grid dimensions, square parameters, and the output filename.

## Requirements

1. **Square Drawing Function**: Generate a functi9on to draw a square on a user-defined grid space using ASCII characters only.
1. **File Output**: Save the representation to a file, including grid dimensions in the form X Y on the first line of the output file.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. **Optimise**: Optimise the drawing algorithm for both speed and accuracy.
1. **Inputs**: Assume the origin is at the bottom left (first character of the last line out of the output file). 
1. **Arguments**: The arguments are:
 * rows. The number of rows in the output file.
 * columns. The number of colums for each line in the output file.
 * squareSize. The length of an edge of the square.
 * outputFilename. The filename to write the results to.

## Driver Code

The generated code must use the following framework. Wherever there is a comment that states with 'TODO', then fill in the required code to fulfull the requirements of that area.


```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// TODO: include any other required standard headers.

using namespace std;

using Grid = vector<vector<char>>;

struct Arguments {
    int gridRows;
    int gridColums;
    int squareSize;
    string outputFilename;
    bool isValid;

    static Arguments parse(int argc, char **argv) {
        // TODO
    }
};

void drawSquare(Grid& grid, int size) {
    // TODO
}

void writeToFile(const Grid& grid, const string& fileName) {
    // TODO
}

int main(int argc, char **argv) {
    Arguments args = Arguments::parse(argc, argv);
    if (!args.isValid) {
        // TODO
    }

    Grid grid(args.gridRows, vector<args.gridColums(' '));
    drawSquare(grid, args.SquareSize);
    writeToFile(grid, args.outputFilename);

    return 0;
}
```

## Example

```bash
$ ./draw_square 50 50 20 output
$ cat output
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
         ********************
```

## Notes

* Ensure square drawing algorithm accurately represents squares of different sizes.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases, such as negative square sizes etc.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


