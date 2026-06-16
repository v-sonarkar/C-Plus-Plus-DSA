// Binary Subarray with Sum
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to goal.
//It contain only 0's and 1's. A subarray is a contiguous part of the array.
// Time Complexity: O(n) where n is the size of the input array

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int func(vector<int>& nums, int goal) {
    if (goal < 0) return 0;

    int l = 0, r = 0;
    int sum = 0, cnt = 0;

    while (r < nums.size()) {
        sum += nums[r];

        while (sum > goal) {
            sum -= nums[l];
            l++;
        }

        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return func(nums, goal) - func(nums, goal - 1);
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << "Number of subarrays with sum equal to " << goal << ": " << numSubarraysWithSum(nums, goal) << endl; // Expected output: 4

    return 0;
}