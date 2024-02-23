# C++20: Singly Linked List of Variants

## Objective

Generate a [singly-linked list](https://en.wikibooks.org/wiki/Data_Structures/LinkedLists) in C++20 that supports storage of data of various types in each node in the list.

The valid types that can be stored in the list nodes are specified at runtime using variadic templates and the `std::variant` template type.

The implementation must prioritise type safety, fail as early as possible (preferably at compile time), and make use of modern C++20 features and best practises.

## Example Framework

The following is a starting point for the generated code. Note that this framework does not add type constraints or use `static_assert`, which is part of the [Requirements](#Requirements) listed below.

All comments that start with `// TODO:` indicate that code must be generated here.

Code must be generated for the entire class, any nested types, and all methods.

```cpp
// TODO: include all required system headers

// TODO: define any useful concepts

template <typename... Types>
// TODO: add type requirements using concepts defined above
class VariantList {
  using Variant = std::variant<Types...>;
  struct Node {
    // TODO
  };

  VariantList() = default;
  ~VariantList() = default;

  void push_back(const Variant& value); //TODO
  void pop_back(); // TODO
  size_t size(); const // TODO

  template <class T>
  void visitTypes(std::function<void(T) visitor); // TODO
};

```

## Requirements

* The generated code must compile and run using modern C++20.
 * Do not use platform-specific code.
 * Do not generate comments that explain what the code is doing. Rather, create comments that explain why the code is written as it is.
 * Do not use any external libraries or systems.
* The following methods are required:
  * `void push_back(const Variant& value);` Adds a new node to the list.
  * `void pop_back();` Remove the last element from the list.
  * `size_t size();` Return the number of elements in the list.
  * `void visitTypes(std::function<void(T) visitor);` Iterates over the list, executing the given function on each element that stores a value of the given type.
* The generated code must be valid C++20 standard code, and only uses libraries and systems that are in the C++20 standard. This includes the Standard Template Library (STL).

## Implementation Guide

* **Type Safety**: Ensure all types within the `std::variant` are default constructable. This is a requirement from the C++ standard. 
* **Efficiency**: Focus on optimising the list's operations, including adding and removing elements.
* **Modern C++ Practices**: 
 * Leverage C++20 features such as smart pointers (`std::unique_ptr<>`, `std::weak_ptr`, `std::shared_ptr`) for automatic memory management.
 * Use constraints and `static_assert` for compile-time checks.
* **Robustness**: Generate code that implements error handling for edge cases, such as removing an element from an empty list, and to ensure the list remains stable and reliable under various conditions including cases where constructors throw exceptions.
* Use [RTTI](https://en.wikipedia.org/wiki/Run-time_type_information) to assist with writing the contents of the list.

## Testing and Validation

* Generate code that demonstrates the list with a mix of types such as `bool`, `int` and `std::string`. 
 * Use two such different lists.
* Perform various operations to showcase the `Variant List's` versatility and type safety.
* Include code that is commented out, but would fail when compiled due to type constraints.
* Validate the list's behaviour through a series of operations, including adding elements with different value types, removing elements, and visiting nodes that contain values of specific types.

## Sample Output

```
List 1 size: 5
Visited int: 42
List 2 size: 5
Visited double: 3.14
Visited double: 5.67
Visited double: 1.23
```

## Notes

* Explore additional C++20 features to further enhance the generated code.
* Focus on generation of clean, efficient, and maintainable code.
* Do not include comments that state what the code does. Rather, focus on adding meaningful comments on why the code was chosen.

## Bonus

* Provide a free-function that sums all list node values that can be summed. Change the constraints and requirements and static\_asserts as needed to support this functionality.
