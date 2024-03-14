# C++20 - Streaming

Create iostream interface (read and write) for the following C++20 structure:

```cpp
struct Outer {
  string name;
  struct Inner {
    vector<int> values;
  };

  friend ostream& operatpr<<(ostream &os, const Outer &) const; // TODO
  friend istream& operatpr>>(ostream &os, Outer &) const;       // TODO
};
```

## Requirements

1. Include all headers required to compile with a modern C++20 compier.
1. Implement the iostream insertion and extraction methods. Thes are marked by the `TODO` comment.
1. Comments: Add comments to the code only when it adds information about 'why' and not 'what' or 'how'.
1. C++20: Use C++20 and modern techniques.
1. Rethrow errors top main function that adds local contexteual information.
1. Show input and output or an Outer strict ith diffferent contents being serialised and deserialised.

