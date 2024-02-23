// C++20: Singly Linked List of Variants

#include <iostream>
#include <variant>
#include <memory>
#include <type_traits>
#include <stdexcept>

#include <functional>

// Concept to check if the type is default constructible
template <typename T>
concept DefaultConstructible = requires(T t) {
    { T() } -> std::same_as<T>;
};

// Concept to check if the type is numeric
template <typename T>
concept Numeric = requires(T t) {
    { t + t } -> std::convertible_to<T>;
};

// Node struct to represent a node in the singly linked list
template <typename... Types>
struct Node {
    std::variant<Types...> value;
    std::unique_ptr<Node<Types...>> next;

    // Default constructor
    Node() = default;

    // Constructor to initialize the node with a value
    Node(const std::variant<Types...>& value) : value(value) {}
};

// VariantList class representing a singly-linked list of variants
template <typename... Types>
class VariantList {
    using Variant = std::variant<Types...>;
    using NodePtr = std::unique_ptr<Node<Types...>>;

    NodePtr head;
    NodePtr tail;
    size_t length;

    static_assert(std::conjunction_v<DefaultConstructible<Types>...>, "All types in the variant must be default constructible");
    //static_assert(std::conjunction_v<std::is_same<std::variant_alternative_t<0, Variant>, std::variant_alternative_t<sizeof...(Types) - 1, Variant>>...>, "All types in the variant must be of the same type");

public:
    // Default constructor
    VariantList() : head(nullptr), tail(nullptr), length(0) {}

    // Destructor
    ~VariantList() {
        NodePtr current = head;
        while (current) {
            NodePtr next = std::move(current->next);
            current.reset();
            current = std::move(next);
        }
    }

    // Push a new node to the back of the list
    void push_back(const Variant& value) {
        NodePtr new_node = std::make_unique<Node<Types...>>(value);
        if (!head) {
            head = std::move(new_node);
            tail = head;
        } else {
            tail->next = std::move(new_node);
            tail = tail->next.get();
        }
        length++;
    }

    // Remove the last node from the list
    void pop_back() {
        if (!head) {
            throw std::runtime_error("Cannot pop from an empty list");
        }
        if (head == tail) {
            head.reset();
            tail = nullptr;
        } else {
            NodePtr current = head;
            while (current->next != tail) {
                current = current->next.get();
            }
            current->next.reset();
            tail = current;
        }
        length--;
    }

    // Return the number of nodes in the list
    size_t size() const {
        return length;
    }

    // Iterate over the list, executing the given function on each element of a specific type
    template <class T>
    void visitTypes(std::function<void(T)> visitor) {
        NodePtr current = head;
        while (current) {
            if (std::holds_alternative<T>(current->value)) {
                visitor(std::get<T>(current->value));
            }
            current = current->next.get();
        }
    }
};

// Function to sum all list node values that can be summed
template <typename... Types>
int summable_list(const VariantList<Types...>& list) {
    int sum = 0;
    list.visitTypes<int>([&sum](int value) { sum += value; });
    list.visitTypes<long>([&sum](long value) { sum += value; });
    list.visitTypes<float>([&sum](float value) { sum += value; });
    list.visitTypes<double>([&sum](double value) { sum += value; });
    return sum;
}

int main() {
 VariantList<std::string, int, char> list1;
    VariantList<bool, double, float> list2;

    list1.push_back("Hello");
    list1.push_back(42);
    list1.push_back('A');
    list1.push_back(100);
    list1.push_back(std::string("World"));

    list2.push_back(true);
    list2.push_back(3.14);
    list2.push_back(5.67);
    list2.push_back(false);
    list2.push_back(1.23);

    std::cout << "List 1 size: " << list1.size() << std::endl;
    list1.visitTypes<int>([](const int& value) {
        std::cout << "Visited int: " << value << std::endl;
        });

    std::cout << "List 2 size: " << list2.size() << std::endl;
    list2.visitTypes<double>([](const double& value) {
        std::cout << "Visited double: " << value << std::endl;
        });

    return 0;


    list1.push_back("Hello");
    list1.push_back(42);
    list1.push_back('A');
    list1.push_back(100);
    list1.push_back(std::string("World"));

    list2.push_back(true);
    list2.push_back(3.14);
    list2.push_back(5.67);
    list2.push_back(false);
    list2.push_back(1.23);

    std::cout << "List 1 size: " << list1.size() << std::endl;
    list1.visitTypes<int>([](const int& value) {
        std::cout << "Visited int: " << value << std::endl;
        });

    std::cout << "List 2 size: " << list2.size() << std::endl;
    list2.visitTypes<double>([](const double& value) {
        std::cout << "Visited double: " << value << std::endl;
        });

    return 0;
}
