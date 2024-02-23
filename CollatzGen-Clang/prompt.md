# C++20 - Concepts and Coroutines for a Collatz Sequence Generator

## Overview

Implement a `CollatzGenerator` coroutine that produces the **Collatz sequence** from a given starting positive integer.

The Collatz sequence is defined by a recursive relation where for any number \(n\), the next number in the sequence is \( n/2 \) if \( n \) is even, and \( 3n + 1 \) if \( n \) is odd.

The process is repeated for each subsequent term until the sequence reaches `1`.

Along with required coroutine definition, a concept named `IntegerConcept` is required to ensure that the coroutine is only used with integral types that support the operations required for generating the Collatz sequence.

## Problem Statement

Generate C++20 code for a coroutine called `CollatzGenerator` that, when given a positive integer, yields the Collatz sequence for that number until it terminates with the value 1.

To ensure type safety and correct program results, defined a concept named `IntegerConcept` that constrains the types allowed to instantiate `CollatzGenerator`, allowing only types that are integral and support the necessary arithmetic operations.

## Requirements

* **C++20 compliance**: The generated code must be C++20 compliant and use modern best practises. Specifically, coroutines and concepts, and `static\_assert` where concepts cannot be used directly.
* **Concept Implementation**: The `IntegerConcept` must ensure that a given type has the properties of integral types, such as supporting operations like division by 2, multiplication by 3, and the addition of 1. The concept should also ensure the can handle a range of values suffient for the generated Collatz sequence without overflow.
** Type Constraints**: Clearly demonstrate the `IntegerConcept` by attempting to instantiate the generator with both valid and invalid types.
* **Coroiutine Implementation**: The generator must use `co_yield` statements to output each term in the indefinite sequence. 
 * It must correcly deal with termination conditions.

## Error Handling and Edge Cases

* Generate error handling code to deal with incorrect input or values that do not meet the requirements for calculating the Collatz sequence. 
 * Include static and dynamic error handling.
* Handle cases where the type can overflow, notably when dealing with large initial values. 

## Interactive Element

* Create a REPL that reads unsigned integers from `stdin` and for each, write the resulting Collatz sequence as a series of positive integers separated by a single space character. 
* The program terminates when `stdin` reaches EOF or SIGINT is received.

## Sample Output

```
Starting number: 6
Sequence: 6 3 10 5 16 6 4 2 1
```

Demonstrate the results given starting numbers of 6, 13, and 345, along with a compile-time error (commented out) that would result when attempting to use a non-conformant type.


----

# Ideal Response

// TODO

### Sample Output

```
123 23 34 12 1 4345 4356
Starting number: 123
Collatz sequence: 123 370 185 556 278 139 418 209 628 314 157 472 236 118 59 178 89 268 134 67
Starting number: 23
Collatz sequence: 23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 1 1
Starting number: 34
Collatz sequence: 34 17 52 26 13 40 20 10 5 16 8 4 2 1 1
Starting number: 12
Collatz sequence: 12 6 3 10 5 16 8 4 2 1 1
Starting number: 1
Collatz sequence: 1 1
Starting number: 4345
Collatz sequence: 4345 13036 6518 3259 9778 4889 14668 7334 3667 11002 5501 16504 8252 4126 2063 6190 3095 9286 4643 13930
Starting number: 4356
Collatz sequence: 4356 2178 1089 3268 1634 817 2452 1226 613 1840 920 460 230 115 346 173 520 260 130 65
```
