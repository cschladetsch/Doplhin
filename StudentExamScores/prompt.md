# C++20 - Student Results Analysis

Generate code that creates statistics for a group of students based on their exam scores. Use modern C++20 code.

Each student is represented by a structure containing their name and a history of their examination (exam) scores.

## Requirements

1. Define a `Student` struct containing the following fields:
 * `string name`: The full name of the Student.
 * `vector<int> scores`: A vector containing the exam scores for that student.
1. Implement a function named `writeStatistics` that takes a vector of Students as input and writes the following information to `stdout`:
 * Name of each Student.
 * Average score for that student.
 * Highest score for that student.
 * Lowest score for that student.
1. Followed by:
 * Overall average score of all students for all exams.
 * Student(s) with the highest average score.
 * Student(s) with the lowest average score.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Provided Framework

Comments that start with 'TODO' should be replaced by effective code that solves the problem, given the information following the 'TODO' text.

```cpp

// TODO: include required headers

using namespace std;

struct Student {
  string name;
  vector<int> scores;
};

// TODO: generate code for the writeStatistics function

int main() {
  vector<Student> students = {
    {"Alice", {80,85,90}},
    {"Bob", {75,70,65}},
    {"Charlie", {90,95,85}}
  };

  writeStatistics(students);

  return 0;
}
```

### Output

```
Student: Alice
Average Score: 85
Highest Score: 90
Lowest Score: 80

Student Bob:
Average Score: 70
Highest Score: 75
Lowest Score: 65

Student Charlie:
Average Score: 90
Highest Score: 95
Lowest Score: 85

Overall Average Score: 81.67
Student(s) with Highest Average Score: Charlie
Student(s) with Lowest Average Score: Bob
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


