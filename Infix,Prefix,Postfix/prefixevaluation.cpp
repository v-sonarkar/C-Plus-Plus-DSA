
#include <iostream>
#include <stack>
using namespace std;

    

int solve(int val1, int val2, char op)
{
    if (op == '+')
    {
        return val1 + val2;
    }
    else if (op == '-')
    {
        return val1 - val2;
    }
    else if (op == '*')
    {
        return val1 * val2;
    }
    else if (op == '/')
    {
        return val1 / val2;
    }
}

void evaluatePrefixExpression(string s)
{
    stack<int> values; // Stack to store integer values

    for (int i = s.length() - 1; i >= 0; i--)
    {
        int asci = (int)(s[i]);

        if (s[i] >= 48 && s[i] <= 57)
        {                                 // digit
            values.push(asci - 48); // convert char to int and push to values stack
        }
        else
        {
            int val1 = values.top();
            values.pop();
            int val2 = values.top();
            values.pop();

            values.push(solve(val1, val2, s[i]));
        }
    }
    cout << values.top() << endl;
}

int main()
{
    string s;
    cout << "Enter a prefix expression: ";
    cin >> s;
    evaluatePrefixExpression(s);
    return 0;
}