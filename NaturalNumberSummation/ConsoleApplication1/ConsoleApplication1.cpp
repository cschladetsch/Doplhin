#include <iostream>
#include <limits>
#include <string>

using namespace std;

long long sum_multiples(long long limit) {
  // Calculate the number of multiples of 3, 5, and 15 below the limit.
  long long multiples_of_3 = (limit - 1) / 3;
  long long multiples_of_5 = (limit - 1) / 5;
  long long multiples_of_15 = (limit - 1) / 15;

  // Calculate the sums of multiples of 3, 5, and 15 using the arithmetic series formula.
  long long sum_of_multiples_of_3 = (multiples_of_3 * (3 + (multiples_of_3 * 3))) / 2;
  long long sum_of_multiples_of_5 = (multiples_of_5 * (5 + (multiples_of_5 * 5))) / 2;
  long long sum_of_multiples_of_15 = (multiples_of_15 * (15 + (multiples_of_15 * 15))) / 2;

  // Return the sum of multiples of 3 and 5, subtracting the sum of multiples of 15 (which were counted twice).
  return sum_of_multiples_of_3 + sum_of_multiples_of_5 - sum_of_multiples_of_15;
}

int main(int argc, char* argv[]) {
  // Check for a command-line argument.
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <limit>" << endl;
    return 1;
  }

  // Attempt to parse the limit from the command-line argument.
  long long limit;
  try {
    limit = stoll(argv[1]);
  } catch (const invalid_argument&) {
    cerr << "Invalid input: Limit must be an integer." << endl;
    return 1;
  } catch (const out_of_range&) {
    cerr << "Invalid input: Limit is out of range." << endl;
    return 1;
  }

  // Check if the limit is valid.
  if (limit <= 0) {
    cerr << "Invalid input: Limit must be greater than zero." << endl;
    return 1;
  }

  // Calculate and output the sum of multiples.
  long long sum = sum_multiples(limit);
  cout << sum << endl;

  return 0;
}