# C++20 - Base-64 Converter

The project involves creating a base64 encoding and decoding tool using modern C++20 features exclusively. Base64 encoding converts binary data into a text-based format, facilitating transmission over text-based protocols (including HTML), while decoding restores the original binary data.

## Problem Statement

Generate code written in modern C++20 that provides functionality to both encode and decode to and from base64 format. The program only supports  encoding and decoding of files.

## Requirements

1. **Base64 Encoding and Decoding**:
 * Implement functions to convert from binary to text, and text to binary, using the base64 specification outlined below.
1. **File Support**:
 * Implement error handling for I/O errors.
 * There is no requirement to read or write to or from standard input or standard output. Errors must be written to standard error stream.
1. **Memory Management**: Use smart pointers and modern memory management techniques to ensure proper and efficient resource management.
1. **Performance**: 
 * Optimise the generated code for performance where possible, especially when dealing with large files.
 * Use `string_view` if and when needed to avoid temporary copying of data.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Headers**: Ensure the generated code includes all required headers. The code must compile without changes.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. Refer to [RFC4648](https://datatracker.ietf.org/doc/html/rfc4648#section-4) for further details. However, all the necessary information to solve this task is provided in this prompt.

## Conversion Process

The following two sub-sections describe the conversion from binary to base64, and from base64 to text.

### Encoding

* The encoding process takes a sequence of binary data (unsigned 8-bit chars) as input.
* Group the binary data into blocks of 3 bytes (24 bits).
* Each such 3-byte block is divided into four 6-bit chunks.
* The 6-bit binary values are grouped into blocks of 4 bytes (24 bits).
* Each block of 4 bytes is split into three 8-bit chunks (bytes).
* The resulting binary data is the original binary data before encoding.
* The padding character is not essential for encoding, since the number of missing bytes can be inferred from the length of the encoded text.

### Decoding

* The decoding process takes a base64-encoded string as input.
* Each character in the input string is decoded back to its corresponding 6-bit binary value according to the bas64 decoding table provided below.
* The 6-bit binary values are grouped into blocks of 4 bytes (24 bits).
* Each block of 4 bytes is split into three 8-bit chunks (bytes).
* The resulting binary data is the original binary data before encoding.
* Padding:
 * Some base64 specifications require padding of the last 4-byte chunk. Although this is not required in this solution, the following describes best practise to ensure that the program works more robustly:
 * A single `=` indicates that the four characters will decode to only two bytes, while `==` indicates that the four characters will decode to only a single byte. For example: 

| Encoded	| Padding	| Length	| Decoded |
| -------------- | --------- | -------- | -----------|
| bGlnaHQgdw==	| ==	| 1	| light w |
| bGlnaHQgd28=	| =	| 2	| light wo |
| bGlnaHQgd29y	| None	| 3	 |light wor |

---

### Base64 Encoding Table

| Value | Encoding | Value | Encoding | Value | Encoding |Value | Encoding 
|-------|---------|-------|---------|-------|---------|-------|---------|
| 0 | A | 17 | R | 34 | i | 51 | z |
| 1 | B | 18 | S | 35 | j | 52 | 0 |
| 2 | C | 19 | T | 36 | k | 53 | 1 |
| 3 | D | 20 | U | 37 | l | 54 | 2 |
| 4 | E | 21 | V | 38 | m | 55 | 3 |
| 5 | F | 22 | W | 39 | n | 56 | 4 |
| 6 | G | 23 | X | 40 | o | 57 | 5 |
| 7 | H | 24 | Y | 41 | p | 58 | 6 |
| 8 | I | 25 | Z | 42 | q | 59 | 7 |
| 9 | J | 26 | a | 43 | r | 60 | 8 |
| 10 | K | 27 | b | 44 | s | 61 | 9 |
| 11 | L | 28 | c | 45 | t | 62 | + |
| 12 | M | 29 | d | 46 | u | 63 | / |
| 13 | N | 30 | e | 47 | v |
| 14 | O | 31 | f | 48 | w |        (pad) = |
| 15 | P | 32 | g | 49 | x |
| 16 | Q | 33 | h | 50 | y |

---

## Examples

```bash
$ cat input.bin
Hello, World!
$ ./bas64-converter input.bin output.txt encode
$ cat output.txt
SGVsbG8sIFdvcmxkIQ==
$ ./base64-converter output.txt result.txt decode
Hello, World!
```

### Handling Errors

```bash
$ ./base64-converter doesnt_exist output.txt decode
Error: Unable to open file 'doesn_exist' for decoding.
$ ./base64-converter bad_input.txt output.txt decode
Error: Invalid base64 found in 'bad_input.txt' at offset 123
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.

