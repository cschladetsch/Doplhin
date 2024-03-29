#include <iostream>
#include <vector>
using namespace std;

int main() {
  //int n, k;
  //cin >> n >> k;
  //vector<int> a(n);
    vector<int> a{ 8, 2, 3, 4, 5, 6, 7 };

    int k = 2;

  bool found = false;
  for (int i = 0; i <= a.size() - k; i++) {
    bool left = false, right = false;
    for (int j = i; j < i + k; j++) {
      if (a[j] <= a[i - 1]) {
        left = true;
        break;
      }
    }
    for (int j = i + k - 1; j >= i; j--) {
      if (a[j] <= a[i + k]) {
        right = true;
        break;
      }
    }
    if (left && right) {
      found = true;
      break;
    }
  }
  cout << (found ? "YES" : "NO") << endl;
}