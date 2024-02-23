#include <concepts>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <variant>

template <typename T, typename... Ts>
concept Contains = std::is_same_v<std::variant<T, Ts...>, std::variant<Ts...>> || Contains<T, Ts...>;

int main() { }

