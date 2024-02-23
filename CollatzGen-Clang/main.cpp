
#include <concepts>
#include <iostream>
#include <coroutine>

// Concept to ensure we are using an integral type that can handle the necessary operations
template<typename T>
concept IntegerConcept = std::is_integral_v<T> && requires(T x) {
    { x / 2 } -> std::convertible_to<T>;
    { x * 3 } -> std::convertible_to<T>;
    { x + 1 } -> std::convertible_to<T>;
};

// The coroutine implementation that generates the Collatz sequence
template<IntegerConcept T>
class CollatzGenerator {
public:
    struct promise_type {
        T current_value;
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        CollatzGenerator get_return_object() {
            return CollatzGenerator{ handle_type::from_promise(*this) };
        }

        void return_void() {}
        void unhandled_exception() { std::exit(1); }
        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }
    };

    using handle_type = std::coroutine_handle<promise_type>;

    CollatzGenerator(handle_type h) : handle(h) {}
    ~CollatzGenerator() { if (handle) handle.destroy(); }

    CollatzGenerator(const CollatzGenerator&) = delete;
    CollatzGenerator& operator=(const CollatzGenerator&) = delete;

    CollatzGenerator(CollatzGenerator&& other) noexcept : handle(other.handle) {
        other.handle = nullptr;
    }

    CollatzGenerator& operator=(CollatzGenerator&& other) noexcept {
        if (this != &other) {
            if (handle) handle.destroy();
            handle = other.handle;
            other.handle = nullptr;
        }
        return *this;
    }

    T next() {
        handle.resume();
        return handle.promise().current_value;
    }

    bool done() const {
        return handle.done();
    }

private:
    handle_type handle;
};

CollatzGenerator<int> Collatz(int n) {
    while (n != 1) {
        co_yield n;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            if (n > (INT_MAX - 1) / 3) {
                throw std::overflow_error("Integer overflow occurred in Collatz sequence.");
            }
            n = 3 * n + 1;
        }
    }
    co_yield 1;
}

// Main REPL to interactively read integers and print the Collatz sequence
int main() {
    try {
        unsigned int number;
        while (std::cin >> number && !std::cin.eof()) {
            std::cout << "Starting number: " << number << std::endl;
            std::cout << "Collatz sequence: ";
            auto generator = Collatz(number);
            int count = 0;
            while (!generator.done() && count < 20) {
                std::cout << generator.next() << ' ';
                count++;
            }
            std::cout << std::endl;
        }
    } catch (const std::overflow_error& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
    }
    return 0;
}
