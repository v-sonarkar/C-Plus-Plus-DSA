
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void PreviousGreaterElement(int arr[], int n) {
    stack<int> s;
    vector<int> result(n, -1); // Initialize result with -1

    s.push(arr[0]); // Push the first element

    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(arr[i]);
    }

    cout << "Previous Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}




int main(){



    return 0;
}