# C++20 - Longest Consecutive Subsequence

Implement a C++20 program that uses `<ranges>` to solve the following problem:

## Problem Statement

The program is given a set of integers via standard input. The task is to find the longest subsequence of consecutive integers in the list and print its length, along with the elements of the subsequence.

## Input Format

The input consists of a single line containing space-separated integers representing the elements of the list to process. Input is read from standard input (stdin).

## Output Format

Output is written to standard output (stdout). The output contains two lines:
* The first line contains an integer representing the length of the longest subsequence of consecutive integers found in the list.
* The second line contains space-separated integers representing the elements of the longest subsequence.



## Requirements

1. The input list can have up to 10,000 integers.
1. The integers in the list fit within the range of a 32-bit signed integer.
1. Implement the solution using modern C++20 techniques and uses the `<ranges>` library.
1. Ensure the solution efficiently handles large inputs.
1. Provide comments and clear variable names to enhance readability.
1. Trap any errors when parsing the input. Write informative error message to standard error (stderr) and terminate the program.

## Examples

```bash
$ ./find_longest_subsequence
1 2 3 5 6 7 9
3
1 2 3
```
Here, the user entered the sequence '1 2 3 5 6 7 9' and the program output '3' on the first line, which is the length of the longest subsequence of consecutive integers, printed next as '1 2 3'.

```
$ ./find_longest_subsequence
10 11 12 13 foo 14 15
Error: "foo": Integer expected.
```
In this case, the character sequence 'foo' is not a  valid integer, so this is caught and an error message is printed to `stderr`.
