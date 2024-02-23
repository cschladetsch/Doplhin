# C++20 - Typed Tokeniser

Efficient data parsing is pivotal in software development, where systems often interact using text-only representations of data. This requires swift and accurate parsing. To assist with this, the objective of this task is to generate classes that can dissect strings into a series of tokens, each representing different data types.

## Problem Statement
Generate two interconnected classes, `Tokeniser` and `Token`, with the aim of helping with the conversion of raw text into a sequence of tokens, each classified as an integer, string, or boolean value.

Further, the solution must be readily extensible to support other token types.

## Requirements

1. **Token Class**:
 * Must identify and store values of integers, strings and booleans.
 * Must provide methods to retrieve the stored value and type.
 * Use `std::variant` type to avoid unnecessary memory overhead.
 * Use `std::string_view` to allow access to the raw string data of the token.
1. **Tokeniser Class**:
 * Efficiently processes a `std::string_view`, segmenting it into an array of `Token` instances.
 * Handle whitespace and recognise distinct tokens.
 * Use `string_view` to avoid unnecessary copying of string data when creating tokens.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Class Skeletons

```cpp
#include <iostream>
#include <string_view>
#include <iostream>
#include <vector>
#include <variant>

using namespace std;

struct Token {
    enum class Type { Int, String, Bool };

    Token(string_view text);

    template <typename T>
    const T& getValue() const;

    Type getType() const;

    friend ostream& operator<<(ostream& out, const Token& token);
};

struct Tokeniser {
    Tokeniser(string_view input);

    const vector<Token> &getTokens() const;
};
```

## Example

### First example with spaces between tokens
```cpp
std::string_view text == "42 \"hello\" false";
Tokeniser tokeniser(text);
auto tokens = tokeniser.getTokens();
std::copy(tokens.begin(), tokens.end(), std::ostream_iterator<Token>(std::cout, " "));
```

Expected output:

```
(int)42 (string)hello (bool)false
```

### Second example with no spaces between tokens:

```cpp
std::string_view text == "12\"world\"true";
Tokeniser tokeniser(text);
auto tokens = tokeniser.getTokens();
std::copy(tokens.begin(), tokens.end(), std::ostream_iterator<Token>(std::cout, " "));
```

Expected output:
```
(int)12 (string)world (bool)true
```

## Notes

* The use of `string_view` is crucial to reduce fragmenting the heap and maintaining performance by reducing copying of data.
* Robust handling of irregular string input formats is very important to maintain the reliability and integrity of the process.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.

