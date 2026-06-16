// Longest Subarray with at most k zeros
// Given a binary array nums and an integer k, return the maximum number of consecutive 1s in the array if you can flip at most k 0's.
// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(1) because we are using only a constant amount of extra space
#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    int zeros = 0;
    int maxlen = 0;
    
    while (r < nums.size()) {
        if (nums[r] == 0) {
            zeros++;
        }
        
        // If zeros exceed k, shrink the window from the left
        if (zeros > k) {
            if (nums[l] == 0) {
                zeros--;
            }
            l++;
        }
        
        // If the window is valid, calculate and update the maximum length
        if (zeros <= k) {
            int len = r - l + 1;
            maxlen = max(maxlen, len);
        }
        
        r++;
    }
    
    return maxlen;
}