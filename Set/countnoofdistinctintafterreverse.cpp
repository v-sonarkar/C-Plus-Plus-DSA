// Count the number of distinct integers in an array using a set after reversing the array
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void reverseArray(vector<int>& nums) {
    reverse(nums.begin(), nums.end());
}

int countDistinct(vector<int>& nums) {
    unordered_set<int> distinctElements;
    for (int num : nums) {
        distinctElements.insert(num);
    }
    return distinctElements.size();
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 4, 1, 5};
    reverseArray(nums); // Uncomment if you want to reverse the array
    cout << "Number of distinct integers: " << countDistinct(nums) << endl;
    return 0;
}
