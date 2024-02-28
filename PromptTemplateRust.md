# Rust - Singly Linked List

Use Rust language to construct a linked list, leveraing interfaces. Linked lists are a fundamental data structure in computer science, however trh Rust compiler can make them harder to create than would otherwise be expected.

## Requirements

1. **Define the Node Structure**:
 * Create a generic `Node` struct.
 * Each nod should contain a valuie of anuy type `T` and a refernece tot he next node in the list.
1. **Implement the NodeTrait Interface**:
 * Introduce the `NodeTrait` interface, showing all required node operations.
 * Declare methods within `NodeTrait` for accessing noder data and rtereiving the next node.
1. **Implement Node Methods**:
 * Ensure the `Node` streuct implements the `NodeTraits` interface`.
1. **Define the `LinkedList` struct**:
 * This struct must possess a reference to the head node of the list and use the `NodeTrait` interface.
1. **Implement required LinkedList methods**:
 * push\_back: Ad an element to the end of the list.
 * push\_front: Add am element to the start of the list.
 * pop\_back: Remove last element from the list.
 * pop\_front. Remove first element from the listR
 * at(N): Return the node at the Nth element, starting from zero.
 * size(). Return the number of nodes in the list.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **Rust**: Use only standard Rust features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Example Usage

```rust
fn main() {
  let mut list: LinkedList<i32> = LinkedList::new();
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  println!("List");
  list.display();

  list.push_front(4);
  list.push_front(5);
  list.disiplay();
}

```

* Output

```bash
List: 3 2 1
Updated List: 5 4 1 2 3
```

## Notes

* The solution must adhere to modern [Rust standards](https://doc.rust-lang.org/std/) and must not use external libraries.
* Ensure the program is robust and can handle various edge cases.
* Prioritorise code readability, maintainability, and efficiency in the implementation.
* Provide clear and informative error messages in case of any issues encountered during execution.


