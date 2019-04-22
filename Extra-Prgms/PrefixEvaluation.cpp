/*
To Evaluate Prefix Expression
1)Reverse the Expression
2)Proceed normally like postfix and Remeber to change op1 and op2 because in Prefix First popped element will be Operand 1
rather than Postfix where First popped element is op2 (ie., Operand 2)
3)Hence the Answer
*/
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string exp;
    stack <int> S;
    getline(cin,exp);
    int l = exp.length();
    int choice,result;
    reverse(exp.begin(),exp.end());
    char *e = &exp[0];
    while(l!=0)
    {
        if(isdigit(*e))
        {
            *e = *e - 48;
            S.push(*e);
        }
        else
        {
            int op1,op2,ans=0;
            switch(*e)
            {
            case '+':
            {
                op1 = S.top();
                S.pop();
                op2 = S.top();
                S.pop();
                ans = op1 + op2;
                break;
            }
            case '-':
            {
                op1 = S.top();
                S.pop();
                op2 = S.top();
                S.pop();
                ans = op1 - op2;
                break;
            }
            case '*':
            {
                op1 = S.top();
                S.pop();
                op2 = S.top();
                S.pop();
                ans = op1 * op2;
                break;
            }
            case '/':
            {
                op1 = S.top();
                S.pop();
                op2 = S.top();
                S.pop();
                ans = op1 / op2;
                break;
            }
            }
            S.push(ans);
        }
        e++;
        l--;
    }
    result = S.top();
    cout << result;
    S.pop();
}

