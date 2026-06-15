// Capacity to Ship Packages within D Days
// Given an array of weights representing the weights of packages and an integer D representing the number of days,
// the task is to find the minimum capacity of a ship such that all packages can be shipped
//Range of capacity will be from max(weights) to sum(weights) because the ship must be able to carry at least the heaviest package and at most all packages in one go.
// Time Complexity: O(n log m) where n is the number of packages and m is the range of possible capacities (from max(weights) to sum(weights))



#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 1. Find boundaries using standard library functions
        int minCapacity = *max_element(weights.begin(), weights.end());
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);
        
        // 2. Brute force linear scan: Test every capacity from min to max
        for (int cap = minCapacity; cap <= maxCapacity; ++cap) {
            int daysRequired = 1;
            int currentLoad = 0;
            
            // Inline validation loop (Greedy check)
            for (int wt : weights) {
                if (currentLoad + wt > cap) {
                    daysRequired++;     // Switch to the next day
                    currentLoad = wt;   // Assign current package to the new day
                } else {
                    currentLoad += wt;  // Pack it into the current day
                }
            }
            
            // The first capacity that successfully handles the load within 'days' is our answer
            if (daysRequired <= days) {
                return cap;
            }
        }
        
        return maxCapacity;
    }
};


// Binary Search Approach

int shipWithinDaysBinarySearch(vector<int>& weights, int days) {
    int minCapacity = *max_element(weights.begin(), weights.end());
    int maxCapacity = accumulate(weights.begin(), weights.end(), 0);
    
    int low = minCapacity;
    int high = maxCapacity;
    int ans = maxCapacity; // Initialize to the upper bound
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        int daysRequired = 1;
        int currentLoad = 0;
        
        for (int wt : weights) {
            if (currentLoad + wt > mid) {
                daysRequired++;     // Switch to the next day
                currentLoad = wt;   // Assign current package to the new day
            } else {
                currentLoad += wt;  // Pack it into the current day
            }
        }
        
        if (daysRequired <= days) {
            ans = mid;          // Found a valid capacity, record it
            high = mid - 1;     // Look for a smaller, more optimal capacity on the left
        } else {
            low = mid + 1;      // Capacity is too small, move to the right side
        }
    }
    
    return ans;
}








int main() {
    Solution sol;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int D = 5;
    
    cout << "Minimum ship capacity to ship all packages within " << D << " days: " 
         << sol.shipWithinDays(weights, D) << endl; // Expected output: 15
    
    cout << "Minimum ship capacity (Binary Search): " 
         << shipWithinDaysBinarySearch(weights, D) << endl; // Expected output: 15
    
    return 0;
}