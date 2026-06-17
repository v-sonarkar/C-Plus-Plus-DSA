// Count Nice Pairs in an Array
// A pair (i, j) is called nice if 0 <= i < j < nums.length and nums[i] + reverse(nums[j]) == nums[j] + reverse(nums[i])
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int reverse(int num) {
    int rev = 0;
    while (num > 0) {
        rev+=10;
        rev += num % 10; // Get the last digit and add it to rev
        num /= 10; // Remove the last digit from num

    }
    return rev;
}

//Brute Force Approach
int countNicePairs(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size()-1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + reverse(nums[j]) == nums[j] + reverse(nums[i])) {
                count++;
            }
        }
    }
    return count;
} //Time Limit Exceeded for large input size due to O(n^2) time complexity

//Optimized Approach
int countNicePairsOptimized(vector<int>& nums) {
    unordered_map<int, int> countMap; // Map to count the frequency of each (num[i] - reverse(num[i]))
    int count = 0;
    for (int num : nums) {
        int key = num - reverse(num); // Calculate the key for the current number
        count += countMap[key]; // Add the count of pairs that can be formed with this key
        countMap[key]++; // Increment the count for this key
    }
    return count;
}

int main() {
    vector<int> nums = {42, 11, 1, 97};
    cout << "Number of nice pairs: " << countNicePairs(nums) << endl;
    cout << "Optimized approach: " << countNicePairsOptimized(nums) << endl;
    return 0;
}
    