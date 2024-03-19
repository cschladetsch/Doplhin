# File MetaData

Generate a single-file C++20 file that leverages the latest advancements in the language. Use <ranges> and <execution> libraries to do analysis of file types and metadata. 

The output is a file that leverages all the latest C++20 tools to files within directories, helping the user with decision making about what to keep and remove.

Note that 'directory' and 'folder' are homonyns, and both refer to what is known as a 'directory' in UNIX.

## Requirements

1. **Metadata**: Use <filesystem> to extract information as needed.
1. **Reporting**: Write clear output as shown in [examples](#Example).
1. **Pathname**: A pathname is either a filename, or a pathname prefixed by an operating-system-defined file `path`.
1. **File Extentions**: A file extension is the post-fix after the last period `.` character in a pathname.
1. **Input**: All input is provided via command line invocation:
 * --path [path]. The path to start from
 * --recursive. If this argumennt is passed, then the program will act recursively through all folders. Otherwise, it will just act on the folder given.
 * --ext [e1, e2, ..., en]. A comma-separated list of file extensions to consider.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. When representing file sizes, use KB, MB, GB etc as is normally recognised.

## Examples

```bash
$ ./file-metadata --path /path/to/something --ext jpg,png
jpg files:
- count: 4
- size: 5.2MB
png files:
- count: 20
- size: 10.8GB
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



