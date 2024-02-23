# C++20 - ArchiveSuggester (`suggest_archive`) program generation

## Overview

**ArchiveSuggester** is a robust C++20 application written for system administrators and users alike. Its main purpose is to allow power users to audit and report on file systems and file usage. It scans directories to report file modification times, to aid in optimising for selection of files to be archived or moved to external storage. 

It does this by identifying files that are suitable for archiving based on time last used and file size.

## Problem Statement

Both users and admins often find themselves inundated with large volumes of data, making it difficult to keep track of when files are created, accessed, or modified.

As a result of this, storage systems can become cluttered with outdate or unnecessary files, resulting in inefficient use of resources and subsequent performance degradation.

Manual assessment of "file freshness" is not only time-consuming but also prone to human error. This can lead to oversight of critical files that should be archived or even removed from the system (such as stale log files, unconverted video files, etc). This results in increased provisioning, operational and servicing costs due to the excessive manual effort required in maintaining the file systems. We note that many users often have many different storage drives, including fast SSDs, slower SSDs, and similarly for HDDs.

The proposed **ArchiveSuggester" program described here intends to address these issues using modern C++20 in an efficient and robust manner. This is done by filtering files based on their last modification time and file size.

## Requirements

These requirements are designed to ensure comprehensive coverage of all necessary features, while adding robust error handling and user-friendly interactions via the command line.

* Use modern C++20 features and libraries such as `<filesystem>`, `<ranges>`, `<format>` and `<chrono>`.
* Provide comments as needed that prioritorise explaining "why" over "what" in terms of the generated code.

### Command-Line Interface (CLI) Requirements

The following is a detailed list of user-input options passed to the command-line of the program. The arguments can be provided in any order.

* `--directory <path>`: Mandatory. Specifies the starting directory for the scan.
* `--recursive`: Optional. Includes sub-directories in the scan if included as a command line parameter.
* `--exclude <pattern>`: Optional. Exclude files matching the given regex pattern. Use the <regex> library for this.
* `--size <size_in_MB>`: Optional. Files larger than this size are considered for archiving.
* `--time <days>`: Optional. Files not accessed for this number of days considered for archiving.

## Functional Requirements

The core capabilities of the program must support:
* **Directory Traversal** (possibly recursively with the `--recursive` command line option).
* **File Information**: Use C++20's `<filesystem>` to get relative file paths, sizes, and modification times.
* **Time Computation**: Use `<chrono>` to compute and display the time elapsed since each file's last modification.
* **Sorting**: Sort files by modification time and size (possibly using the `<=>` operator), to write logic that matches user preference as expressed via command-line arguments.

## Input Validation

* Use preventative measures to ensure the correctness of user input, safeguarding against invalid data.
* Ensure all input paths and options are validated against he provided set of defined rules for format and consistency.

## Error Handling

* Clearly define responses for different error types. Exceptions caught locally should add local contextual information then re-throw to the caller.
* Errors include but are not limited to:
 * Access problems for files.
 * Invalid inputs.
 * Other unexpected errors.
* If an error is encountered, write a short useful message to `stderr` and continue processing.

## Output Formatting

Output should be structured in a way that is clear, concise, and meaningful. 

* Format the output with a header, detailed list of files to be archived, and a summary of excluded files. Use tabulation for readability.
* Respect cross-platform issues when writing output, such as end-of-line characters. Do not attempt to colorise it.

## Performance

* Generate code that efficiently handles large folders while minimising file system access times.
* Consider using threads for each (large) folder, or otherwise discuss how performance issues could be addressed.

## Sample Output

```bash
$ ./archive_suggest -d /path/to/folder --size 100 --recursive --time 30
25 files found
Files exceeding 100MB and not accessed in last 30 days:
./old-backup.zip
./data/project-v1.tar.gz
./logs/yearly/2022/summary.log
[... other files listed here ...]
```
Another example with different parameters, excluding `*.rar` files

```
$ ./archive_suggest -d path --size 50 --time 10 --exclude "*.rar"
25 files found
Excluded 10 files matching "*.rar"
Files exceeding 50MB and not accessed in last 10 days:
./path/backup.zip
./path/game.zip
[... other files listed here ...]
```

## Notes for Code Generation

* The AI is expected to generated a C++20 program that adheres to modern coding standards and meets all the requirements.
* Emphasise readability, extensibility, and efficient resource use.
* Consider using thread pools to improve performance
* If generating the full code result would result in reaching a token limit, formatting or other errors, regenerate the output with a summary and outline of how to approach this problem, and provide key code usage patterns.

