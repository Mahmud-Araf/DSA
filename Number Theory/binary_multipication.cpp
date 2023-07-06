// implementation of binary multipication  (a*b)%m

#include<bits/stdc++.h>
using namespace std;

long long int binary_multipication(long long int a,long long int b, long long int m)
{
    long long int ans=0;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans+a)%m;
        }

        a=(a+a)%m;
        b>>=1;
    }

    return ans%m;
}