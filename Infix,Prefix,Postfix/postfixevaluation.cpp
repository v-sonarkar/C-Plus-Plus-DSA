
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

int evaluatePostfixExpression(string s)
{
    stack<int> values;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            values.push(s[i] - 48); // convert char to int and push to values stack
        }
        else
        {
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();

            values.push(solve(val1, val2, s[i]));
        }       
           
    return values.top();
}
}
int main()
{
    string s;
    cout << "Enter a postfix expression: ";
    cin >> s;
    cout << "Result: " << evaluatePostfixExpression(s) << endl;
    return 0;
}