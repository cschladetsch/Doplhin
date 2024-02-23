# C++20: Creatie a Word Usage Histogram

## Summary
This project guide aims to demonstrate the utilization of modern C++20 features, including ranges, views, lambdas, and hash maps, to develop a word usage histogram. The program will read text input from standard input (stdin), count the occurrences of each unique word, and then display a histogram representing the word usage.

## Problem Statement
Analyzing text to determine the frequency of word usage is a common problem in data analysis, offering insights into the text's composition and themes. The challenge is to efficiently process the input text, identify unique words, count their occurrences, and then present this data in the form of a histogram. The solution should leverage C++20's ranges and views for efficient text processing, lambdas for concise functional operations, and hash maps for effective storage and retrieval of word counts.

## Requirements
1. **Input Processing**: Read text input from stdin until EOF is encountered. Consider words to be sequences of characters separated by whitespace, punctuation, or other delimiters.
2. **Word Normalization**: Convert all words to a uniform case (lowercase or uppercase) to ensure accurate counting without case sensitivity issues.
3. **Histogram Creation**:
   - Use a hash map (e.g., `std::unordered_map`) to store word counts.
   - Utilize C++20 views to efficiently filter, transform, and process the input data.
   - Apply lambdas for custom operations, such as normalization and filtering.
4. **Display Results**: Output the histogram in a simple text-based format, showing each word and its corresponding count, sorted by frequency in descending order.

## Sample Output
Given a text input through stdin, the program should produce an output similar to the following, which represents the word usage histogram:

```
the: 10
and: 9
to: 7
of: 5
a: 5
in: 3
```

## Notes
- **Efficiency Considerations**: Pay attention to the efficiency of operations, especially when processing large texts. The use of views and lambdas can help minimize unnecessary copies and computations.
- **C++20 Compliance**: Ensure that the compiler and standard library in use fully support C++20 features required for this project. And no toher external libraries.
- **Error Handling**: Implement basic error handling for I/O operations, ensuring the program behaves gracefully in case of input errors or interruptions.
- **Extendability**: Consider structuring the code to allow easy extension, such as adding options for different output formats or additional input processing features in the future.
