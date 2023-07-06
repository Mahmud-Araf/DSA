// implementation of checking vaid parentheses sequences

/*
Author:
ABDULLAH AL MAHMUD ARAF(prime_23)
CSE,Dhaka University
Creation Time : 12:16:05
Creation Date : 03/06/2023
*/

#include<bits/stdc++.h>
using namespace std;

bool valid(string str)
{
    int len = str.length();
    int i = 0;

    stack<char> st;

    while (i < len)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (st.empty())
            {
                return false;
            }
            else if (str[i] == ')' && st.top() != '(')
            {
                return false;
            }
            else if (str[i] == '}' && st.top() != '{')
            {
                return false;
            }
            else if (str[i] == ']' && st.top() != '[')
            {
                return false;
            }
            st.pop();
        }
        i++;
    }

    return st.empty();
}


int main()
{
    string str="(({[author]})(23{[araf]})([]))";

    cout<<valid(str)<<endl;
}