# Rust - Singly Linked List

Use Rust to construct a linked list, leveraging interfaces. Linked lists are fundamental, and even though most modern languages offer default implementations, it's good to know how to they work and why.

## Requirements

1. **Define Node**:
 * Create a generic `Node` structure.
 * Each such node mus contain a value of type `T` and a references to the next node in the list.
1. **Implment NodeTrait Interface**:
 * Generate a `NodeTrait<T>` interface, showing required node operations.
 * Write methods within the `NodeTrait<T>` for accessing node data and getting the next node.
1. **Implment `Node<T>` Method**:
 * The `Node` sstructure must implement the `NodeTraits<T>` interface.
1. **`LinkedList<T>`**:
 * Create a structure that controls and manages a set of Nodes.
 * This structure must possess a reference ot hte head node of hte liust and use the `NodeTrait<T>` interface.

1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Rust**: Use only standard modern Rust features and libraries. Do not use external libraries.

## Example Usage

```rust
// TODO required supported code

fn main() {
  let mut list : LinkedList<i32> = LinkedList<i32>qa::new();
  
}
```

## Notes

* The solution must adhere to modern Rust standards and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.



