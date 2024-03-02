# C++20 - Create a Trie data structure

## Trie Basics

In computer science, a trie, also called digital tree or prefix tree, is a type of k-ary search tree, a tree data structure used for locating specific keys from within a set.

These keys are most often strings, with links between nodes defined not by the entire key, but by individual characters. In order to access a key (to recover its value, change it, or remove it), the trie is traversed depth-first, following the links between nodes, which represent each character in the key.

Unlike a binary search tree, nodes in the trie do not store their associated key. Instead, a node's position in the trie defines the key with which it is associated. This distributes the value of each key across the data structure, and means that not every node necessarily has an associated value."*P

## Requirements

1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. **Operation**: There are three modes for running the program:
 * Insertion: When invoked with the `--add` argument, the user provides items to the trie, as words separated by whitespace. Every time the a word is added it is updated to persistence storage on disk with a filename called called `.trie`. This process ends until EOF is read.
 * Search: When invoked with the `--search` argument, the next argument is used as the term to search for (unquoted). The program returns 1 (indicating general error) if the term is not found. Else the program returns 0.
 * Deletion: When invoked with the `--delete` argument, the next agument is removed from the trie and the persistent storage is updated.
1. **Effiecicy**: Implement insertion, searching and deltion operations efficiently.
1. **Memory Management**: Use responsible and safe memory usage and proper deallocation using the standard `*_ptr` mechanisms.
1. **Unicode Support**: There is no need to support UNICODE. ANSI is sufficient.
1. **Thread Safety**: The program can assume it runs in a single-threaded environment.
1. **Data Generation**: Create a large random datafile for testing.
1. **Performance Testing**: Show some performance tests for inserting, search, and deletion using `std::chrono`.
1. **Documentation**: Provide clear documentation on the design, implementation, and usage.
1. **Unit Tests**: Do not provide unit tests.
1. **Case Sensitivity**: Words are not case sensitive.

## Sample Usage

```bash
$ ./trie --add
hello world bye
$ ./app --search hello
$ echo $?
0
$ ./app --search spam
1
$ ./app --delete hello
$ ./app --search hello
$ echo $?
1
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


