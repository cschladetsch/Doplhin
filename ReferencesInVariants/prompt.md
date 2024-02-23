# C++20: Allow references in std::variant<> types

## Overview

This tasks involves combining `std::variant` and `std::reference_wrapper`.

## Problem Statement

There is a problem with `std::variant<>`: it cannot use reference types directly.

This has some deep implications and requires a deeper understanding of C++ beyond beginner or even learned users.

The problem is simple to state: 
* Allow std::variant to accept reference types.
* Continue to allow std::variant to take values from the stack.

## Requirements

* **C++20 Compliance**: Use modern C++20 standard code. Do not use other libraries.
* **Referehce Encapsulation**: The generated code will allow using reference types in a `std::variant<>` type.
* **Visitation**: Use `std::visit` and callable objects to shyow polymorhpic behavior over variant-held references.
* **Type Safety**: The generated code must avoid issues such as dangling references and type mis-mathces.
 * Find and report problems as early as possible.
 * Compile-time errors are far better than run-time errors.
 * In either case, provide useful contextual error messages.

## Sample Output

Imagine a scenario where the program manipulates `int` and `douible` values through a `std::variant<>` encapsulating their references. The output sould reflect the modifications made to these values via the variant:

```
Initial Values: a = 10, b = 0.5
Changed via Variant:

a = 15(int)
b = 25.5(double)

```

## Notes

* **Object Lifetimes**:
* **Access Patterns**:
* **Performance**:


