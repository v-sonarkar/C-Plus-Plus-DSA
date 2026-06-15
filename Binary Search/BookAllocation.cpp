// Book Allocation

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//Brute Force Approach
// Helper function to calculate the number of students needed
int fun(vector<int> &arr, int pages) {
    int n = arr.size();
    int stu = 1, pagesStudent = 0;

    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            stu++;
            pagesStudent = arr[i];
        }
    }
    return stu;
}

// Main function rewritten exactly like the blackboard image
int findPages(vector<int> &arr, int n, int m) {
    // Edge case: If books are fewer than students, allocation is impossible
    if (m > n) return -1;

    // low = max(arr)
    int low = *max_element(arr.begin(), arr.end());
    
    // high = sum(arr)
    int high = accumulate(arr.begin(), arr.end(), 0);

    // loop from pages = low to high
    for (int pages = low; pages <= high; pages++) {
        int cntStu = fun(arr, pages);
        if (cntStu == m) {
            return pages;
        }
    }
    return -1; 
}

// Binary Search Approach
int findPagesBinarySearch(vector<int> &arr, int n, int m) {
    if (m > n) return -1; // Edge case: More students than books

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        int cntStu = fun(arr, mid);

        if (cntStu <= m) {
            ans = mid;         // Found a valid allocation, record it
            high = mid - 1;    // Look for a smaller maximum page count on the left
        } else {
            low = mid + 1;     // Too many students needed, increase the page count
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();
    int m = 2;

    cout << "Minimum number of pages (Brute Force): " << findPages(arr, n, m) << endl; // Expected output: 60
    cout << "Minimum number of pages (Binary Search): " << findPagesBinarySearch(arr, n, m) << endl; // Expected output: 60

    return 0;
}