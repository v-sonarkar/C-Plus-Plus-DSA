#include <iostream>
#include <stack>
using namespace std;

string solve(string val1, string val2, char op)
{
    string s = "";
    s.push_back(op);
    s += val1;

    s += val2;

    return s;
}

string evaluatePostfixExpression(string s)
{
    stack<string> values;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            values.push(string(1, s[i])); // convert char to string and push to values stack
        }
        else
        {
            string val2 = values.top();
            values.pop();
            string val1 = values.top();
            values.pop();

            values.push(solve(val1, val2, s[i]));
        }

        return values.top();
    }
}

int main()
{
    string s = "79+4*8/3-";
    cout << "Result: " << evaluatePostfixExpression(s) << endl;
    return 0;
}