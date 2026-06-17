// Three-Digit Even Numbers
#include <iostream>
#include <vector>   
#include <unordered_map>
#include <algorithm>
using namespace std;


// Function to find all three-digit even numbers that can be formed using the given digits
vector<int> findEvenNumbers(vector<int>& digits) {
  
   int n=digits.size();
    unordered_map<int, int> m; // Map to count the frequency of each digit
    for (int digit : digits) {
        m[digit]++;
    }

    vector<int> result; // Vector to store the resulting even numbers
    for (int i = 100; i <= 999; i+=2) {
        int x=i;
        int a=x%10; // Get the last digit
        x/=10;
        int b=x%10; // Get the middle digit
        x/=10;
        int c=x%10; // Get the first digit

        if(m.find(a)!=m.end() && m[a]>0) { // Check if the last digit is available
            m[a]--; // Decrease the count of the last digit
            if(m[a]==0) m.erase(a); // Remove the digit from the map if its count becomes zero
            if(m.find(b)!=m.end() && m[b]>0) { // Check if the middle digit is available
                m[b]--; // Decrease the count of the middle digit
                    if(m[b]==0) m.erase(b); // Remove the digit from the map if its count becomes zero
                if(m.find(c)!=m.end() && m[c]>0) { // Check if the first digit is available
                    result.push_back(i); // If all digits are available, add the number to the result
                }
                m[b]++; // Restore the count of the middle digit
            }
            m[a]++; // Restore the count of the last digit
        }



}
return result; // Return the vector of three-digit even numbers

}
   
 int main() {
    vector<int> digits = {2, 1, 3, 0};
    vector<int> evenNumbers = findEvenNumbers(digits);
    cout << "Three-digit even numbers that can be formed: ";
    for (int num : evenNumbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

