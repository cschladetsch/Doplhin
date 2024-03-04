#include <concepts>
#include <stdexcept>

// Define the 'Prime' concept to check if a number is prime at compile-time
template <typename T>
concept Prime =
    // Ensure the number is an integer greater than 1
    std::integral<T> && T{1} < T &&
    // Check if the number is divisible only by itself and 1
    requires(T i = 2) {
        { i * i } -> std::same_as<T>; // Square i and check if it's equal to the number
        while (i * i <= T{}) {
            { T{} % i } -> std::same_as<T{0}>; // Check if the remainder is 0
            i++;
        }
    };

// Helper function to perform prime number check and throw an exception if not prime
template <Prime T>
void assert_prime(T number) {
    static_assert(Prime<T>, "The provided number is not a prime number.");
}

int main() {
    try {
        // Test case for a prime number
        assert_prime(17);

        // Test case for a non-prime number
        assert_prime(10); // This will throw an exception at compile-time
    } catch (const std::exception& e) {
        // Handle the exception and provide additional context
        throw std::runtime_error("Prime number assertion failed: " + std::string(e.what()));
    }

    return 0;
}
