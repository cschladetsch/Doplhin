
#include <iostream>
#include <vector>

using namespace std;

bool checkSubarray(vector<int> a, int k) {
    // Check if the first k elements satisfy the condition
    int leftMax = a[0];
    for (int i = 1; i < k; i++) {
        if (a[i] < leftMax) {
            return false;
        }
        leftMax = max(leftMax, a[i]);
    }

    // Check if the last k elements satisfy the condition
    int rightMax = a[a.size() - 1];
    for (int i = a.size() - 2; i >= a.size() - k; i--) {
        if (a[i] < rightMax) {
            return false;
        }
        rightMax = max(rightMax, a[i]);
    }

    // Check if the middle elements satisfy the condition
    for (int i = k; i < a.size() - k; i++) {
        if (a[i] < leftMax || a[i] < rightMax) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> a{ 8, 2, 3, 4, 5, 6, 7 };

    if (checkSubarray(a, 1)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}

