//First Step for Selection Sort is to find the smallest element in the array and swap it with the first element.
//Then we find the second smallest element and swap it with the second element and so on until the entire array is sorted.


#include <iostream>
using namespace std;

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // --- SELECTION SORT CODE START ---
    for (int i = 0; i <= n - 2; i++) {
        
        int mini = i; // Highlighted red in your image
        
        for (int j = i+1; j <= n - 1; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        
        // --- COMPLETION: The swap step after the inner loop finishes ---
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
    // --- SELECTION SORT CODE END ---

    // Printing the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


//Time Complexity: O(n^2) in all cases (best, average, worst) because of the nested loops.
//Space Complexity: O(1) because it is an in-place sorting algorithm that does not

//Using vectors instead of arrays for better memory management and dynamic sizing.
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++) {
        int mini = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

