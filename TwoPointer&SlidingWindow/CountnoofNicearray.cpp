// Count Number of Nice Subarrays
// Given an array of integers nums and an integer k, return the number of "nice" subarrays.
// A "nice" subarray is defined as a subarray with exactly k odd numbers.
// Time Complexity: O(n) where n is the size of the input array

#include <iostream>
#include <vector>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    // Implementation for counting nice subarrays
    int count = 0;
    int left = 0, right = 0;
    int oddCount = 0;

    while (right < nums.size()) {
        if (nums[right] % 2 == 1) {
            oddCount++;
        }

        while (oddCount > k) {
            if (nums[left] % 2 == 1) {
                oddCount--;
            }
            left++;
        }

        if (oddCount == k) {
            count++;
        }

        right++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << "Number of nice subarrays: " << numberOfSubarrays(nums, k) << endl; // Expected output: 2

    return 0;
}
