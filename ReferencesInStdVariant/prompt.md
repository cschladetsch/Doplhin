# C++20: Support References in std::variant

## Summary

Generate code that implements polymorphism in C++20 by usaing `std::variant` and `std::reference_wrapper` for safe and efficient handling of reference and value types stored in a variant.

## Requirements

* **C++20 Compliance**: Use only C++20 librariues and features in the implementation.
* **Reference Encapsulation**: Show how to store references within a `std::variant` using `std::reference_wrapper`.
* **Simulated Polymorphism**: Show polymorhpic behavior using `std::visit` and callabale objects (e.g, `std::function`).
* **Type Safety**: Prevent dangling references and type mismatches.
 * Use C++20 concepts and `static_assert`
* **Error Handling**: Deal and report all errors as soon as possible, starting at compile-time. Rethrow exceptrions with added locally available contextual data.
* Provide example driver `main` function that prdodces the [Sample Output](#Sample Output).

## Example Framework

```cpp
#include <variant>
#include <functional>
#include <concepts>

template <typename... Types>
using ReferenceVariant = std::variant<std::reference_wrapper<Types>...>;

template <typename... Types>
concept PolymorphicOperation = requires(ReferenceVariant<Types...> var) {
  { std::visit([](auto &&arg) { /* define polymorphic behavior */}, var )};
};

template <PolymorphicOperation... Ops>
void applyOpereation(ReferenceVariant<Ops...>& var) {
  std:: visit([](auto &&arg) { /* define polymorphic behavior */), var);
}
```

## Sample Output

```
Intital values: a = 10, b = 20.5
After modifcation via variant:
Intital values: a = 14, b = 23.4
```

## Notes

* **Object Lifetimes**:
* **Comparative Analysis**:
* **Access Patterns**:
