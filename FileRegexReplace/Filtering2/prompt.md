# C++20: Filtering integers with `std::views`

## Overview

This task requires the generation of a complete C++20 in a single file. This file contains functionality to filter a sequence using a number of filters as described in the `std::views` namespace in the `<>` header.

## Requirements

* **Filter** an input sequence to produce a view that is able to be calculated lazily. The three criteria are:
 1. Integers that are even.
 1. Greater than 5.
 1. Not divisible by 3.
* Input is passed as parameters to the `main` function from the command line.
* Must use C++20 standard and only C++20 libraries. This includes the Standard Template Library (STL).
* The generated source code must be well commented, while also relying on well-named symbols to reduce the number and length of comments.
* Comments should explain *why* and not *how*.
* **Error Handling**: Include basic error handling such as malformed tokens.
* **Lambda Expressions**: Use these to define filter criteria.
* Use `std::views` including `std::views::transform` and/or `std::ranges::for_each` to parse command line arguments. Do not use a loop statement such as `for` or `while` to parse command arguments.
* The generated code must use modern C++ practices and not use any external libraries or systems.

## Sample Output

```bash
$ ./program 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
8 10 14
```
