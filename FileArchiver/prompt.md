# C++20 - File Archiver

Generate a C++20 program to assist in managing files within given directories, through customisable file selection criteria, and destinations given via command line arguments.

## Requirements

1. **Scanning Directories**: Use `<filesystem>` and related modern C++20 libraries.
1. **Identification**:
 * Write a mechanism to find files based on user-defined criteria, especially name and age.
1. **Command Line Interface**:
 * Enable user to specify the source and destination folders, as well as file selection criteria, via the command line.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. **Default Behaviour**: Do nothing other than show available arguments if augments are missing or corrupt.
1. **File Movement**: Use practical and careful means to move files, trapping all errors, and mitigate potential issues such as overwriting destination files but allowing for skipping same files.
1. **Be Efficient**: Strive for most efficient code.
1. Command Line Usage: is described in [Sample usage](#sample-usage). Specifically:
 * --min-age: Only consider files other than the number of days.
 * --min-size: Only consider files that are lager than the given number of kilobytes.

## Sample Usage

```bash
$ ./file-manager /path/to/source /path/to/destination --min-age 30 --min-size 60000
$ # in this case, the program ./file-manager will find all files that are older than 30 days and larger thana 6000 kilobytes and move to the the specified target destination folder
$ ./file-manager /path/ --min-age 40 --min-size 1024
Error: Missing destination folder
$ ./file-manager /from /to --min-age foo
Error: foo is not a valid number
$ ./file-manager /from /to --min-age 10 --min-size bar
Error: bar is not a valid number
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



