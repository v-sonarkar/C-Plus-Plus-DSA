// Introduction to Maps in C++
// A map is a collection of key-value pairs where each key is unique and maps to a specific value.
// Maps are implemented as balanced binary search trees (like Red-Black Trees) in C++
// It Sores Frequently Used Data in Key-Value Pairs
// It Provides Fast Lookups, Insertions, and Deletions Based on Keys
// insert()->O(1), find()->O(1), erase()->O(1) on average

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Create a map to store student names and their corresponding grades
    unordered_map<string, int> studentGrades;

    // Insert some key-value pairs into the map
    studentGrades["Alice"] = 85;
    studentGrades["Bob"] = 90;
    studentGrades["Charlie"] = 78;

    // Accessing values using keys
    cout << "Alice's grade: " << studentGrades["Alice"] << endl;
    cout << "Bob's grade: " << studentGrades["Bob"] << endl;

    // Check if a key exists in the map
    if (studentGrades.find("Charlie") != studentGrades.end()) {
        cout << "Charlie's grade: " << studentGrades["Charlie"] << endl;
    } else {
        cout << "Charlie is not found in the map." << endl;
    }

    // Erase a key-value pair from the map
    studentGrades.erase("Bob");

    // Check if Bob's grade is still in the map
    if (studentGrades.find("Bob") != studentGrades.end()) {
        cout << "Bob's grade: " << studentGrades["Bob"] << endl;
    } else {
        cout << "Bob is not found in the map." << endl;
    }

    return 0;
}
