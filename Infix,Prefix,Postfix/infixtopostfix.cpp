#include <iostream>
#include <stack>
using namespace std;

// using stack to evaluate prefix expression
// op val1 val2
// example: + 2 3

int priority(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
string solve(string val1, string val2, char op)
{
   
    string s = "";
    
    s += val1;
    s += val2;
    s.push_back(op);
    return s;
}

int evaluatePrefixExpression(string s)
{
    stack<char> ops;      // Stack to store operators
    stack<string> values; // Stack to store integer values

    for (int i = s.length() - 1; i >= 0; i--)
    {
        int asci = (int)(s[i]);

        if (s[i] >= 48 && s[i] <= 57)
        {                                 // digit
            values.push(string(1, s[i])); // convert char to string and push to values stack
        }
        else
        {

            if (ops.size() == 0)
            {
                ops.push(s[i]);
            }
            if (s[i] == '(')
            {
                ops.push(s[i]);
            }
            if (ops.top() == '(')
            {
                ops.push(s[i]);
            }
            else if (priority(s[i]) > priority(ops.top()))
            {
                ops.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (ops.top() != '(')
                {
                    string val2 = values.top();
                    values.pop();
                    string val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    string res = solve(val1, val2, op);
                    values.push(res);
                }
                ops.pop(); // pop the '(' from the stack
            }
            else
            {
                while (ops.size() > 0 && priority(s[i]) <= priority(ops.top()))
                {
                    string val2 = values.top();
                    values.pop();
                    string val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    string res = solve(val1, val2, op);
                    values.push(res);
                }
                ops.push(s[i]);
            }
        }
    }
    while (!ops.empty())
    {
        string val2 = values.top();
        values.pop();
        string val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        string res = solve(val1, val2, op);
        values.push(res);
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