//implementation of sieve of eratosthenes

/* Sieve of Eratosthenes is the algorithm to precalculate prime numbers upto  any number n effectively

Time Complexity:O(nlog(log(√n)))
Space Complexity:O(n)

n=max number
*/
#include<bits/stdc++.h>
using namespace std;

const int n=1000001;

bool is_prime[n]={};

void sieve(int n)
{
    is_prime[0]=is_prime[1]=true;

    for(long long int i=2;i<=n;i++)
    {
        if(!is_prime[i])
        {
            for(long long int j=i*i;j<=n;j+=i)
            {
                is_prime[j]=true;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(!is_prime[i])
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;

}
