#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op) {
    if(op=='+'||op=='-'){
        return 1;
    }
    else if(op=='*'||op=='/'){
        return 2;
    }
    else{
        return 0;
    }
}




//using Two stack one forstoring integer and another for storing operators and then pop the top two elements from the integer stack and pop the top element from the operator stack and perform the operation and push the result back to the integer stack until the operator stack is empty and finally return the top element of the integer stack as the result of the expression
int evaluateInfixExpression(const string& s) {

    stack<int> values; // Stack to store integer values
    stack<char> ops;   // Stack to store operators
    for(int i=0;i<s.length();i++){
        int asci=(int)(s[i]);

        if(s[i]>=48 && s[i]<=57){ // digit
           values.push(asci-48); // convert char to int and push to values stack
        }
        else {

            if(ops.size()==0){
                ops.push(s[i]);
            }
            if(s[i]=='('){
                ops.push(s[i]);
            }
            if(ops.top()=='('){
                ops.push(s[i]);
            }
            else if(priority(s[i])>priority(ops.top())){
                ops.push(s[i]);
            }
            else if(s[i]==')'){
                while(ops.top()!='('){
                    int val2=values.top();
                    values.pop();
                    int val1=values.top();
                    values.pop();
                    char op=ops.top();
                    ops.pop();
                    if(op=='+'){
                        values.push(val1+val2);
                    }
                    else if(op=='-'){
                        values.push(val1-val2);
                    }
                    else if(op=='*'){
                        values.push(val1*val2);
                    }
                    else if(op=='/'){
                        values.push(val1/val2);
                    }
                }
                ops.pop(); // pop the '(' from the stack
            }
            else{
                while(ops.size()>0 && priority(s[i])<=priority(ops.top())){
                    int val2=values.top();
                    values.pop();
                    int val1=values.top();
                    values.pop();
                    char op=ops.top();
                    ops.pop();
                    if(op=='+'){
                        values.push(val1+val2);
                    }
                    else if(op=='-'){
                        values.push(val1-val2);
                    }
                    else if(op=='*'){
                        values.push(val1*val2);
                    }
                    else if(op=='/'){
                        values.push(val1/val2);
                    }
                }
                ops.push(s[i]);
            }
    
            

        }
    }
    while(!ops.empty()){
        int val2=values.top();
        values.pop();
        int val1=values.top();
        values.pop();
        char op=ops.top();
        ops.pop();
        if(op=='+'){
            values.push(val1+val2);
        }
        else if(op=='-'){
            values.push(val1-val2);
        }
        else if(op=='*'){
            values.push(val1*val2);
        }
        else if(op=='/'){
            values.push(val1/val2);
        }
    }
    return values.top();
}
    int main() {
    string s;
    cout << "Enter an infix expression: ";
    cin >> s;

    int result = evaluateInfixExpression(s);
    cout << "Result: " << result << endl;
    return 0;
}
