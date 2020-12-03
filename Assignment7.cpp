//============================================================================
// Name        : Assignment7.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;


    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            s.push(expr[i]);
            continue;
        }

        if (s.empty())
           return false;

        switch (expr[i])
        {
        case ')':

            x = s.top();
            s.pop();
            if (x=='{' || x=='[')
                return false;
            break;

        case '}':

            x = s.top();
            s.pop();
            if (x=='(' || x=='[')
                return false;
            break;

        case ']':

            x = s.top();
            s.pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }
    return (s.empty());
}

int main()
{
    string expr;
    cout<<"Enter the string that you want to check paranthesis of:\n";
    cin>>expr;

    if (areParanthesisBalanced(expr))
        cout << "Balanced paranthesis";
    else
        cout << "Unbalanced paranthesis";
    return 0;
}
