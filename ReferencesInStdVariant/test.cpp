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
