// implementation of binary exponential (a*b)%m

#include<bits/stdc++.h>
using namespace std;

long long int binexp(long long int a,long long int b,int m)
{
  long long int ans=1;
  while(b>0)
  {
    if(b&1)
    {
      ans=(ans*a)%m;
    }
    a=(a*a)%m;
    b>>=1;
  }
  return ans%m;
}