# Problem Statement

The `grep` command is essential for filtering text or searching through file for specific patterns.

I would like a program written in C++20 that uses `<regex>` and `<filesystem>` libraries that provides a basic implementation of *grep*.

## Requirements

1. **Command Line Parsing**: The generated program must accept arguments there the first argument is the pattern to search for, and the later arguments are the files to search within.
1. **Regex Matching**: Use C++20's `<regex>` library to match the given pattern against each line in the input files list.
1. **File Reading**: Open and read the contents of each specified file line by line, applying the search pattern to each.
 * **Output**: For each match found, print the line to `stdout`. Include the filename in the output if there are multiple input lines.
1. **Error Handling**: The generated program must handle cases where files cannot be opened or read, printing appropriate errors to `stderr`.
1. **Simplicity**: Do not attempt to deal with escaped characters. You may even treat the regex just as a simple text string.


## Sample Usage

Given the command `./grep "pattern" file1.txt file2.txt`:

```
file1.txt: This line contains pattern.
file2.txt: Also contains pattern.
```

If A file does not exist or cannot be opened, print an error message like:

```
Error: Cannot open 'file3.txt' for reading.
```

## Notes

* Use C++20 features such as ranges and concepts, if applicable, to make the generated code more efficient and type-safe.
* Consider using `<filesystem>` for file and path handling.
* Do not be overly fancy - stick to the requirements.

