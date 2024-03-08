# C++20 - Segment Line Draw

## Problem Statement

Generate a C++ program to render a line segment on a grid and write it to a file. The progri=am should provide a user-friend interface for specifying grid dimensions, line segement end end points, and output file name.


## Requirements

1. **Line Segment Drawing Function**:
1. **File Output**: Use C++20 features for code effieciency and readability. Do not use external libraries..
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Example Driver Code

Genereate code for all comments that start with TODO:

```cpp
// TODO: add required include files. These must be standard C++20 files.

struct Arguments {
    int gridRows;
    int gridColumns;
    int startX;
    int startY;
    int endtX;
    int endtY;
    string outputFileName;
    bool isValid;

    static Arguments parse(int argc, char** argv) {
        if (argc != 9) {
            return printHelp(argv[0]);
        }

        try {
        }
        catch (exception& e) {
            throw runtime_error(string("Bad Arguemnts :") + e.what());
        }
    }

    static Arguments printHelp(char *appName) {
        cout << appName << "<grid_rows <grid_columns> <startx>  <starty> <endx> <endy> <outfilr";
        return { 0,0,0,0,0,0,false };
    }
};

void drawLineLegment();

void writeToFile(Grid const& grid, const string& fileName) {
    ofstream out(fileName);
    if (!out) {
        throw runtime_error("Failed to open " + fileName);
    }

    out << grid.size() << grid[0].size() << endl;
    for (const auto & row : grid) {
        for (char c : row) {
            out << c << ' ';
        }
        out << endl;
    }
}

int main(int argc, char** argv) {
    try
    {
        Arguments args = Arguments::parse(argc, argv);
        if (!args.isValid) {
            throw runtime_error("Bad args");
        }

        Grid grid(args.gridRows, vector<char>(args.gridColumns, ' '));
        drawLineLegment(grid, args)'
        writeToFile(grid, args.outoutFileName);
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

```

## Notes

* Consider corner cases when generating the drawing algirithm, including zero-length lines, and ensure that horonizontal and vertical lines lines are treated specially.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



