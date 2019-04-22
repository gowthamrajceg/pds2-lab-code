#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string exp;
    stack <char> S;
    cout << "Enter Expression :";
    getline(cin,exp);
    int l = exp.length();
    char *e = &exp[0];
    while(l!=0)
    {
        if(*e=='('||*e=='['||*e=='{')
        {
            S.push(*e);
        }
        else if(*e==')'||*e==']'||*e=='}')
        {
            if(S.empty())
            {
                cout << "No, The Parenthesis are Not Balanced" << endl;
                return 1;
            }
            else
            {
                if(*e==')'&& S.top()=='(')
                {
                    S.pop();
                }
                else if(*e==']'&& S.top()=='[')
                {
                    S.pop();
                }
                else if(*e=='}'&& S.top()=='{')
                {
                    S.pop();
                }
                else
                {
                    cout << "No, The Parenthesis are Not Balanced" << endl;
                    return 1;
                }
            }
        }
        e++;
        l--;
    }
    if(S.empty())
    {
        cout << "Yes, The Parenthesis are Balanced" << endl;
    }
}
