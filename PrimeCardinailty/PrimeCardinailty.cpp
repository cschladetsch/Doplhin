#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) { cin >> a[i]; }

  vector<bool> prime(1000001, true);
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i * i <= 1000000; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= 1000000; j += i) { prime[j] = false; }
    }
  }

  vector<bool> found(1000001, false);
  for (int i = 0; i < n; i++) {
    for (int j = 2; j * j <= a[i]; j++) {
      if (prime[j] && a[i] % j == 0) {
        found[j] = true;
      }
    }
  }

  int count = 0;
  for (int i = 0; i < 1000001; i++) {
    if (found[i]) { count++; }
  }

  cout << count << endl;
}
