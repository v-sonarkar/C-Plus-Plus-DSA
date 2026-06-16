// Maximum Points You Can Obtain from Cards
// You have several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning of the row or from the end of the row. You have to take exactly k cards.
// Time Complexity:O(2*k) because in the worst case we will be taking k cards from the left and k cards from the right, but since we are only taking k cards in total, it simplifies to O(k).
// Space Complexity: O(1) because we are using only a constant amount of extra space


#include <iostream>


#include <vector>
#include <algorithm>

using namespace std;

int maxScore(vector<int>& nums, int k) {
    int n = nums.size();
    int lsum = 0;
    int rsum = 0;
    int maxSum = 0;
    
    // 1. Calculate sum of the first k elements
    for (int i = 0; i < k; i++) {
        lsum += nums[i];
    }
    
    maxSum = lsum;
    int rindex = n - 1;
    
    // 2. Slide the window: remove from left, add from right
    for (int i = k - 1; i >= 0; i--) {
        lsum -= nums[i];
        rsum += nums[rindex];
        rindex--;
        
        maxSum = max(maxSum, lsum + rsum);
    }
    
    return maxSum;
}