# C++20 - Compile Time Linked List

Generate a C++20 program to create an immutable linked list. Leverage C++20's features such as `consteval`, `constinit` and `constexpr` to construct a linked list data structure that cannot be modified after compilation.



## Requirements

1. **Immutable Elements**: Ensure the elements of the list cannot be modified at runtime.
1. **Compile-Time Construction**: Implement the linked list construction process entirely at compile-time.
1. **LinkedList Operations**: Implement basic list operations:
 * Insertion of an element.
 * Deletion of an element.
 * Traversing elements.
 * Obtaining the size of the list (number of elements).
1. **Functions**: Provide 
 * `make_immutable_linked_list`: A template function that constructs an immutable linked list at compile time.
 *  `list_add`: Template function that computes the sum of elements in an immutable linked list.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Provide appropriate compile-time error messages for invalid operations performing operations on an empty list.
1. **Concepts**: Use C++20 concepts as necessary to ensure good error messages are reported at compile-time.

### Performance Requirements

* The compile-time construction of the immutable linked list should have a reasonable compile-time overhead, allowing for efficient compilation even for large lists.
* The run-time performance of list operations, such as traversal and sum calculation, should be optimised to minimise overhead compared to traditional run-time constructed linked lists.

## Provided Framework

```cpp
// TODO: Include necessary header files

// TODO: Define immutable linked list

// Create an immutable linked list at compile-time 
template <typename... Args>
constexpr auto make_immutable_linked_list(Args... args) {
    // TODO
}

// Calculate the sum of elements in an immutable linked list at compile-time 
template <typename List>
constexpr auto list_sum(const List& list) {
}

int main() {
    constexpr auto list = make_immutable_linked_list(1,2,3,4,5);
    constexpr auto sum = list_sum(list);
    static_assert(sum == 1+2+3+4+5);
    return 0;
}

```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



