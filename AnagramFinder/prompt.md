# C++20 - Anagram Finder

## Problem Statement

Generate a program that identifies anagrams within a list of strings. Anagrams are words or phrases formed by rearranging the litters of another word or phrase, using all the original letters exactly once.

In this case, only words are required. A word is a sequence of letters with no whitespace. The case does not matter.

## Requirements

1. **Input**: 
 * Read a list of words from standard input `stdin` and identify anagrams within the list.
 * Ignore all punctuation.
 * Input words are separated by whitespace after all punctuation has been removed.
1. **Output**: 
 * Display groups of anagrams found, as per [Sample Usage](#sameple-usage) section below. Specifically:
 * Find all anagrams within a group of words.
 * Write a header named "Group N", where N monotonically increases for each new group, starting from 1.
 * Under each "Group N", list all anagrams on a different line, preceded by `- `.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
 * Use `<string_view>` library to reduce memory copy overhead.
 * Use `<algorithm>` STL library as needed to reduce the amount of code generated.
 * Use `<ranges>` library as needed.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Sample Usage

The following shows a sample session in `bash` script.

```bash
$ cat ./input.txt
listen silent below elbow act cat desserts stressed
$ cat ./input.txt | ./find_anagrams
Group 1
- listen
- silent
Group 2
- below
- elbow
Group 3
- act
- cat
Group 4
- desserts
- stressed
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases. 
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.
* Show example usage that differs from that provided in this prompt.


