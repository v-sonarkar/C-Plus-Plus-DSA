// Two Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Map to store number and its index
    for (int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i]; // Calculate the complement
        if (numMap.find(rem) != numMap.end()) { // Check if complement exists in the map
            return {numMap[rem], i}; // Return indices of the two numbers
        }
         else {
            numMap[nums[i]] = i; // Store the current number and its index in the map
        }
    }
    return {}; // Return an empty vector if no solution is found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices of the two numbers: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}