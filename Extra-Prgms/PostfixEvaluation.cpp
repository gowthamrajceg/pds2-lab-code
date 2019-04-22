#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string exp;
    stack <int> S;
    getline(cin,exp);
    int l = exp.length();
    int choice,result;
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
                op2 = S.top();
                S.pop();
                op1 = S.top();
                S.pop();
                ans = op1 + op2;
                break;
            }
            case '-':
            {
                op2 = S.top();
                S.pop();
                op1 = S.top();
                S.pop();
                ans = op1 - op2;
                break;
            }
            case '*':
            {
                op2 = S.top();
                S.pop();
                op1 = S.top();
                S.pop();
                ans = op1 * op2;
                break;
            }
            case '/':
            {
                op2 = S.top();
                S.pop();
                op1 = S.top();
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
