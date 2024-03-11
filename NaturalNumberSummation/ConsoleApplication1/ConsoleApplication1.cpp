#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Calculate the sum of natural numbers below a limit that are multiples of 3 or 5.
long long sumMultiples(long long limit) {
    // Calculate the number of multiples of 3 and 5 below the limit.
    long long numMultiples3 = (limit - 1) / 3;
    long long numMultiples5 = (limit - 1) / 5;

    // Calculate the number of multiples of both 3 and 5 (multiples of 15).
    long long numMultiples15 = (limit - 1) / 15;

    // Calculate the sum using the formula for the sum of an arithmetic series.
    long long sumMultiples3 = numMultiples3 * (3 + (numMultiples3 * 3)) / 2;
    long long sumMultiples5 = numMultiples5 * (5 + (numMultiples5 * 5)) / 2;
    long long sumMultiples15 = numMultiples15 * (15 + (numMultiples15 * 15)) / 2;

    // Return the sum of multiples of 3 and 5, subtracting the sum of multiples of 15 to avoid double counting.
    return sumMultiples3 + sumMultiples5 - sumMultiples15;
}

// Handle command line arguments and perform input validation.
vector<long long> parseArguments(int argc, char* argv[]) {
    vector<long long> limits;

    // Iterate over command line arguments, skipping the program name.
    for (int i = 1; i < argc; i++) {
        try {
            // Convert argument to a long long integer.
            long long limit = stoll(argv[i]);

            // Validate the limit is positive.
            if (limit <= 0) {
                throw invalid_argument("Limit must be positive.");
            }

            limits.push_back(limit);
        } catch (invalid_argument& e) {
            // Handle invalid arguments.
            cerr << "Error: Invalid limit '" << argv[i] << "'. " << e.what() << endl;
            exit(1);
        } catch (out_of_range& e) {
            // Handle out-of-range arguments.
            cerr << "Error: Limit '" << argv[i] << "' is too large." << endl;
            exit(1);
        }
    }

    // Check if any limits were provided.
    if (limits.empty()) {
        cerr << "Error: No limits provided." << endl;
        exit(1);
    }

    return limits;
}

int main(int argc, char* argv[]) {
    try {
        // Parse command line arguments and extract limits.
        vector<long long> limits = parseArguments(argc, argv);

        // Calculate and output the sum for each limit.
        for (auto limit : limits) {
            long long sum = sumMultiples(limit);
            cout << sum << endl;
        }

        return 0;
    } catch (exception& e) {
        // Handle internal errors.
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
