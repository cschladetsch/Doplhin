# C++20: Bookstore System Improvement

## Overview

This task is to improve an online bookstore's software system, focused on using C++20 features to deal with book data management.

The goal is to address inefficiencies, improve backend operations, and improve end-user experience.

The bookstore's current software struggles with efficient book data management, which negatively affects use experience and performance. 

The goal of this task is to generate code that addressee these problems.

## Requirements

1. Use practical C++20 code, and no other sources or libraries.
  * The Standard Template Library (STL) is  a part of C++20 standard.
1. **Enhance Book Class**: Implement a `Book` class encapsulating author, title, ISBN, using the C++20 spaceship operator `<=>` for complex comparisons and sorting by price, with secondary criteria for ties.
1. **Static Type Safety**: Generate a `PriceFilter` concept that enforces numeric types for price-related operations.
1. **Optimise Data Management**: Use `std::ranges::sort` for sorting and `std::views::filter` for filtering.
1. **Syntax Improvements**: Use lambdas, `std::format`, and auto type deduction.

## Sample Output

* **Input**: A diverse collection of books with detailed attributes.
* **Operation**: Execute price-based sorting and filtering operations within a $40-$50 price range.
* Note that the usage of "Name" and 'cost' are just place-holders. The actual output will use hypothetical data.

```
Books sorted by Price:
- "Name1": cost1
- "Name2": cost2
- "Name3": cost3

Filtered Books:
- "Name4": cost4
```

## Notes

* **Performance**:
 * Outline specific means for performance testing, including tools and benchmarks to evaluate and judge.
 * Discuss optimisation strategies, such as parallel computation and advanced data structures, to improve scalability.
* **User Experience**: Detail how backend improvements can translate to frontend features like real-time search suggestions and dynamic filtering.
* **Scalability**: Emphasise architectural considerations and design patterns that ensure the system is well-prepared for future expansions, feature integrations, and other technological advancements like integration with new third-party libraries.

