// Nth Root of a Number
// Time Complexity: O(log n)
// Space Complexity: O(1)
// using linear search approach will give us O(n) time complexity but using binary search we can reduce it to O(log n)

#include <iostream>
using namespace std;


int nthRoot(int n, int m) {
    if (m == 0) return 0;
    if (n == 1) return m;

    int low = 1;
    int high = m;
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long power = 1;

        // Calculate mid^n
        for (int i = 0; i < n; i++) {
            power *= mid;
            if (power > m) break; // No need to continue if power exceeds m
        }

        if (power == m) {
            return mid; // Found exact nth root
        } else if (power < m) {
            result = mid; // Store the floor value
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result; // Return the floor of the nth root
}

int main() {
    int n = 3; // Example: Find the cube root
    int m = 27; // Example: Number to find the nth root of
    std::cout << "Floor of " << n << "th root of " << m << " is " << nthRoot(n, m) << std::endl;
    return 0;
}