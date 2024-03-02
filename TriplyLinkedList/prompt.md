# C++20 - Triply Linked List

Design a course management system ir a university to streamline the process of managing cources, prerequieists, and corequiresites.

## Problem Statement

The current course management system at the university is umbersome and inefficient. The task is to generate code to create a modernised system that simplifies course management, allowing for the addition of courses, definition of of prerequieists and corequiresites, and retreival of relevant cource information.

## Requirements

1. Develope a _triply linked list_ data structure to represent cources and their relationships with prerequieists and corequiresites.
1. Implement functions to add cources and define their prerequieists an corequiresites.
1. Comments: Add comments to the code, focusing on "why" and not "how" or "what".
1. C++20: Use only standard C++20 features and libraries. Do not use external libraries.
 * Use `*_ptr` systems for memory management.
1. Error Handling: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.
1. Assume the code is single-threaded.

## Example Declarations

All the instructions provided in comments after 'TODO' must be generated.

```cpp
// TODO: Include relavant headers.

struct CourseNode;

using CourseVariant = std::variant<std::shared_ptr<CourseNode>, std::vector<std::shared_ptr<CourceNode>>>;

typedef const std::string &CourseName;

struct CourseNode {
  CourceName name;
  std::shared_ptr<CourseNode> next;
  std::weak_ptr<CourseNode> prev;
  CourseVariant prerequisiutes;
  CourseVariant corequisiutes;

  // TODO: remainder of implmentation as required
};

class SchedulingSystem {
public:
  typedef const std::string& StringArg;
  typedef std::vector<std::shared_ptr<CourseNode>> Courses;

  void addCourse(StringArg courseName);
  void addPrerequiute(StringArg courseName, StringArg prerequiteName);
  void addCorequisite(StringArg courseName);
  Courses getPrerequisites(CouseName) const;
  Courses getCorequisites(CourseName) const;
};
```

## Notes

* Design the sysem with modularity in mind.
* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



