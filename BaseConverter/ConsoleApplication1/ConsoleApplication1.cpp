#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

// Converts a number from any base to decimal.
// number: The number to convert.
// base: The base of the number.
long long convert_to_decimal(const string& number, int base) {
    // Validate the base range.
    if (base < 2 || base > 36) {
        throw invalid_argument("Base must be between 2 and 36");
    }

    long long decimal_value = 0;
    int power = 0;

    // Iterate through the number in reverse order.
    for (auto it = number.rbegin(); it != number.rend(); ++it) {
        int digit_value;

        // Convert digits 0-9 to their decimal values.
        if (isdigit(*it)) {
            digit_value = *it - '0';
        }
        // Convert letters A-Z to their decimal values (10-35).
        else {
            digit_value = toupper(*it) - 'A' + 10;
        }

        // Check if the digit is valid for the given base.
        if (digit_value >= base) {
            throw invalid_argument("Invalid digit for the given base");
        }

        // Calculate the decimal value of the digit.
        decimal_value += digit_value * pow(base, power);
        power++;
    }

    return decimal_value;
}

int main(int argc, char** argv) {
    try {
        // Check if the correct number of arguments is provided.
        if (argc != 3) {
            cout << "Usage: ./base_converter <number> <base>" << endl;
            return 1;
        }

        string number = argv[1];
        int base = stoi(argv[2]);

        // Convert the number to decimal and print the result.
        cout << convert_to_decimal(number, base) << endl;

    } catch (const exception& e) {
        // Catch and rethrow exceptions with additional context.
        cerr << "Error: " << e.what() << endl;
        throw;
    }

    return 0;
}
