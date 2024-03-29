#include <iostream>

template <typename... Types>
struct Sequence { };

template <typename S1, typename S2>
struct ConcatTypes;

template <typename... Types1, typename... Types2>
struct ConcatTypes <Sequence<Types1...>, Sequence<Types2...>> {
    using type = Sequence<Types1..., Types2...>;
};

template <typename Head, typename Tail>
struct LinkedList {
    using head_type = Head;
    using tail_type = Tail;
};

template <typename ... Types>
constexpr auto make_immutable_linked_list(Sequence<Types...>) {
    if constexpr (sizeof...(Types) == 0) {
        return nullptr;
    }

    return new LinkedList<typename Types::type, decltype(make_immutable_linked_list(Sequence<Types...>{})) > {};
};

template <typename List>
constexpr auto list_sum_helper(const List& list) {
    if constexpr (std::is_same_v<typename List::head_type, std::nullptr_t>) {

    }

    return list.head_type::value + list_sum_helper<typename List::tail_type>(list.tail);
}

template <typename List>
constexpr auto list_sum(const List& list) {
    return list_sum_helper(list);
}

int main() {
    return 0;
}
