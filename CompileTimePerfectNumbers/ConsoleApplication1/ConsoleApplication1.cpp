#include <iostream>

// A constexpr function to determine if a number is perfect at compile time.
constexpr bool isPerfect(int num) {
    // Calculate the sum of divisors up to the square root of the number.
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            // Add both the divisor and its quotient.
            sum += i + num / i;
        }
    }

    // Return true if the sum of divisors equals the number.
    return sum == num;
}

int main() {
    // Test cases for perfect numbers.
    static_assert(isPerfect(6));
    static_assert(isPerfect(28));

    // Print results.
    std::cout << "6 is perfect: " << std::boolalpha << isPerfect(6) << std::endl;
    std::cout << "28 is perfect: " << std::boolalpha << isPerfect(28) << std::endl;

    return 0;
}
