# C++20 - Drawing an Ellipse to a File

Generate a modern C++20 program to render an ellipse on a grid and save it to a file. 
The program must provide a user-friendly interface for specifying grid dimensions, ellipse parameters, and the output file.

## Requirements

1. **Ellipse Drawing Function**:
1. **File Output**:
1. **Centred Ellipse**:

1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Example Driver Code

All comments that start with TODO must be generated.

```cpp
// TODO Include all required headers

using namespace std;

using Grid = vector<vector<char>>;

struct Arguments {
  // TODO
  bool isValid;

  static Arguments parse(int argc, char **argv) {
    Arguments args;
    // TODO
    return args;
  }
};

void showHelp() {
  // TODO
}

void writeEllipise(Grid &grid, const Arguments& args) {
  // TODO
}

void writeToFile(const Grid &grid, string_view filename) {
  // TODO
}

int main(int argc, char **argv) {
  try {
      auto args = Arguments::parse(argc, argv);
      if (!args.isValid) {
         showHelp();
         return 1;
      }
      Grid grid;
      writeEllipise(grid, args);
      writeToFile(grid, args.outputFileName);
      return 0;
  } catch (exception &e) {
     cerr << "Error: " << e.what() << endl;
  }

  return 1;
}

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


