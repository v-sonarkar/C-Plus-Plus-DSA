#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
void nextGreaterElement(int arr[], int n) {
    vector<int> result(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }

    cout << "Next Greater Elements (Brute Force): ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}

// Stack Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
void nextGreaterElementUsingStack(int arr[], int n) {
    vector<int> result(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(arr[i]);  // Push original element
    }

    cout << "Next Greater Elements (Stack): ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);
    nextGreaterElementUsingStack(arr, n);

    return 0;
}