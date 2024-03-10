#include <iostream>

// A constexpr function to determine if a given number is perfect at compile time.
constexpr bool isPerfect(int n) {
    // Calculate the sum of divisors, starting from 1 and excluding the number itself.
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }

    // Return true if the sum of divisors equals the number.
    return sum == n;
}

int main() {
    // Compile-time verification of perfect numbers using static_assert.
    static_assert(isPerfect(6));  // 1 + 2 + 3 = 6.
    static_assert(isPerfect(28)); // 1 + 2 + 4 + 7 + 14 = 28.

    // Output results for demonstration.
    std::cout << "6 is perfect: " << std::boolalpha << isPerfect(6) << std::endl;
    std::cout << "28 is perfect: " << std::boolalpha << isPerfect(28) << std::endl;

    return 0;
}
/*
```

**Explanation:**

- The `isPerfect()` function uses a `constexpr` declaration to enable compile-time evaluation.
- It iterates through numbers from 1 to `n-1` to find divisors of `n`.
- The sum of divisors is calculated and compared to `n` to determine perfection.
- In `main()`, `static_assert` is used to verify the perfection of numbers at compile time.
*/