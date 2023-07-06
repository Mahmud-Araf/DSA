//implementation of mod of big number

/* This algorithm is useful for finding mod of very large number which can be fitted in long long int or _int128t_

Time Complexity: O(n),
Space Complexity:O(k)

n=size of string
k=const space
*/

#include<bits/stdc++.h>
using namespace std;

int bigmod(string s,int m)  //we should input the big number as string as it might be as big as 1e500
{   int r=0;
    for(int i=0;i<s.size();i++)
    {
        r=(r*10+s[i]-'0')%m;
    }
    return r;             // r will be the result of number%m
}                       
