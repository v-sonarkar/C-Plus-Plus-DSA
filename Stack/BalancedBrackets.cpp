//If you see open brackets then push it into the stack and if you see closing brackets then check if the stack is empty or not if it is empty then return false else pop the top element from the stack and check if it is matching with the closing bracket or not if it is not matching then return false else continue this process until the end of the string and at the end check if the stack is empty or not if it is empty then return true else return false

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(const string& str) {
    if (str.empty()) return true;
    if (str.length() % 2 != 0) return false; // Odd length strings cannot be balanced

    stack<char> s;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if (s.empty()) return false; // No matching opening bracket
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }
    return s.empty(); // If stack is empty, all brackets were matched

}
int main() {
    string str;
    cout << "Enter a string of brackets: ";
    cin >> str;

    if (isBalanced(str)) {
        cout << "The brackets are balanced." << endl;
    } else {
        cout << "The brackets are not balanced." << endl;
    }

    return 0;
}