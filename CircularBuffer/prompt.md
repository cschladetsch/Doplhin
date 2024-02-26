# C++20 - Circular Buffer

Generate a C++20 conformant program that demonstrates tje usage of a cicular buffer.

## Problem Satement

1. Efficient Design. Implement a circular buffer for memoryu isage performance in streming scenarios.
1. Template Based. Use templates to enable the circular buffer to use different types of storage.
1. Concepts. Use `concepts` to trap errors errors at compile time.

## Requirements

1. **Include methods to add and remove elements**: fro,m the buffer
1. **Customisable**: Allow users of the date structure designate the underlyinmg container to use, as well as its size, while providing sensible defaults.
 * Include methods for adding to the buffer.
 * Add ability to remove elements from the end of the buffer.
 * The buffer is FIFO: First in, first out.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Example

```cpp
// TODO: incliude required headers
// TODO: Define the CicularBuffer class

template <typename T, std::size_t N>
class CircularBuffer {
    // TODO: implement definitions:
    void push(const T &argument);
    std::optional<T> pop();
    bool empty() const;
    int size() const;
    void clear();
};

int main(int argc, char **argv) {
    CircularBuffer<int, 5> b;
    b.push(1);
    b.push(2);
    b.push(3);

    assert(b.size() == 3);
    while (!b.empty()) {
        auto item = b.pop();
        if (!item) {
            exit(0);
        }
        // process item

    }
    return 0;
}
```

## Notes

* The solution must adhere to modern C++20 standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



