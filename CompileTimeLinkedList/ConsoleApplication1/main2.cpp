#include <concepts>
#include <utility>

// Define a concept to ensure that a type is a compile-time list.
template <typename T>
concept CompileTimeList = requires {
    typename T::value_type;
    typename T::next;
    requires std::same_as<typename T::next, const CompileTimeList*>;
};

// Define the immutable linked list structure.
template <typename T>
struct CompileTimeLinkedList {
    constexpr T value;
    const CompileTimeLinkedList<T>* next;

    // Constructor for creating a list node.
    consteval CompileTimeLinkedList(T value, const CompileTimeLinkedList<T>* next = nullptr)
        : value(value), next(next) {}
};

// Create an immutable linked list at compile-time.
template <typename... Args>
constexpr auto make_immutable_linked_list(Args... args) {
    return CompileTimeLinkedList<std::common_type_t<Args...>>(args..., nullptr);
}

// Calculate the sum of elements in an immutable linked list at compile-time.
template <CompileTimeList List>
constexpr auto list_sum(const List& list) {
    if constexpr (list.next == nullptr) {
        return list.value;
    } else {
        return list.value + list_sum(*list.next);
    }
}

// Function to get the size of a compile-time linked list.
template <CompileTimeList List>
constexpr int list_size(const List& list) {
    if constexpr (list.next == nullptr) {
        return 1;
    } else {
        return 1 + list_size(*list.next);
    }
}

int main() {
    // Create an immutable linked list at compile-time.
    constexpr auto list = make_immutable_linked_list(1, 2, 3, 4, 5);

    // Calculate the sum of elements at compile-time.
    constexpr auto sum = list_sum(list);
    static_assert(sum == 1 + 2 + 3 + 4 + 5);

    // Get the size of the list at compile-time.
    constexpr auto size = list_size(list);
    static_assert(size == 5);

    return 0;
}