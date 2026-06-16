// Count Number of Nice Subarrays
// Given an array of integers nums and an integer k, return the number of "nice" subarrays.
// A "nice" subarray is defined as a subarray with exactly k odd numbers.
// Time Complexity: O(n) where n is the size of the input array

#include <iostream>
#include <vector>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int count = 0;
    int left = 0;
    int oddCount = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] % 2 != 0) {
            oddCount++;
        }

        while (oddCount > k) {
            if (nums[left] % 2 != 0) {
                oddCount--;
            }
            left++;
        }

        if (oddCount == k) {
            count += right - left + 1; // Count all subarrays ending at 'right' with exactly k odd numbers
        }
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << "Number of nice subarrays: " << numberOfSubarrays(nums, k) << endl; // Expected output: 2

    return 0;
}
