// Square Root of a Number
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int floorSqrt(int n) {
    if (n == 0) return 0;

    int low = 1;
    int high = n;
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        } else if (square < n) {
            result = mid; // Store the floor value
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n = 25;
    std::cout << "Floor of square root of " << n << " is " << floorSqrt(n) << std::endl;
    return 0;
}