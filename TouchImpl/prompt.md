# C++20 - Implement `touch`

## Overview

This code generation task requires a basic implementation of the commonly known UNIX `touch` command using modern C++20. The `touch` command is used in Unix-like operating systems, namely _Linux_ and derivatives, to change file access and modification times.

It has a secondary use of creating new empty files. 

## Problem Statement

File creation and timestamp modifications are essential functionality for many applications, from build systems to automated backup solutions. Implementing a version of `touch` command allows the use the understand the basics of the new `<filesystem>` library as well as other systems in C++20.

## Requirements

* **File Creation**: If the given file(s) do not exist, create them as new empty files.
* **Timestamp Modification**: If a given file exists, update its access and modification times to the current time. Consider using using the C++20 `<filesystem>` and `<chrono>` libraries for this.
* **Command-line Arguments**: The arguments are an explicit list of files. No regular expressions are expected. There is no idea of a "recursive touch".
* **Error Handling**: Write error handling support as needed. Add local contextual data to any exceptions caught, then re-throw to the caller function.
 * If `main` encounters an error, it should report an informative message to `stderr` stream and continue processing.
* **Use C++20 Features**: Use `<filesystem>`, `<chrono>`, and `<format>` libraries as needed.

## Sample Output

The following command creates `foo` and `bar` files (after deleting them), uses the command to **touch** them, then uses the built-in `ls` command to show they were created.

```bash
$ rm -rf foo bar && ./custom_touch foo bar && ls
bar foo
```

Another - this time altering the last modified date for a file:

```bash
$ ls -l spam
-rw-r--r-- 1 christian 197121 0 Feb 18 10:36 spam
$ ./custom_touch spam && ls -l spam
-rw-r--r-- 1 christian 197121 0 Feb 18 10:38 spam
```

## Notes

* Emphasise the use of modern C++20 features and libraries.
* Do not use other external libraries.




