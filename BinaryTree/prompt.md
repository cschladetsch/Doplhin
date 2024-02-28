# C++20 - Binary Tree

Generate a program that implements a Binary Tree that gets input from a filename passed on the command line. The BinaryTree skeleton is given as:

```cpp
template <class T>
class BinaryTree {
   // ....
}
```

Then enter a REPL (Read Eval Print Loop) to find the closest number to that provided via stdin.

## Binary Tree

A binary tree is a tree data structure in which each node has at most two child nodes, referred to as the left child and the right child. Each node also contains a value that is used for comparison.

## Functionality

* File Input: Read whitespace-separated integers from the contents of a filename supplied by the user on the command-line.
* Add these to a Binary Tree.
* Closest Number Search: Implement a search for an integer with the smallest  absolute difference from the provided target value.
* REPL Interaction: Continuously prompt the user for a target number. If no input is provided, or EOF or SIGINT is found, terminate the program.

## Requirements

1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. **Memory Management**: Use `std::shared_ptr`, `std::weak_ptr` and `std::unique_ptr` as needed to ensure no usage of `new` or `delete` operators.
1. **Termination**: If no value is provided when the user is prompted with `>`, the program terminates.
1. **Do not use anything in the STL (Standard Template Library)**: 
1. **Strict Weak Ordering**: A Strict Weak Ordering is a Binary Predicate that compares two objects, returning true if the first precedes the second. This predicate must satisfy the standard mathematical definition of a strict weak ordering. The precise requirements are stated below, but what they roughly mean is that a Strict Weak Ordering has to behave the way that "less than" behaves: if a is less than b then b is not less than a, if a is less than b and b is less than c then a is less than c, and so on.
1. **Constraints**: Provide constraints that the given type `T` given to the `BinaryTree` conforms to **strict weak ordering**.

## Sample Usage

```bash
$ cat numbers
10 22 17 38 15

$ ./closest_number numbers
> 25
22
> 40
38
> 
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
