#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool precedence(char ch1,char ch2);
int pre(char ch);
int main()
{
    string exp,result;
    stack <char> S;
    getline(cin,exp);
    int l = exp.length();
    int choice;
    char *e = &exp[0];
    while(l!=0)
    {
        if(isalpha(*e)||isdigit(*e))
        {
            result = result + *e;
        }
        else if(*e=='(')
        {
            S.push(*e);
        }
        else if(*e==')')
        {
            while(!S.empty())
            {
                if(S.top()=='(')
                {
                    S.pop();
                    break;
                }
                result = result + S.top();
                S.pop();
            }
        }
        else
        {
            while(!S.empty()&& S.top()!= '(' && precedence(S.top(),*e))
            {
                result = result + S.top();
                S.pop();
            }
            S.push(*e);
        }
        e++;
        l--;
    }
    while(!S.empty())
    {
        result = result + S.top();
        S.pop();
    }
    cout << result;
}
bool precedence(char ch1,char ch2)
{
    int pre1 = pre(ch1);
    int pre2 = pre(ch2);
    if(pre1>=pre2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int pre(char ch)
{
    switch(ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    }
}
