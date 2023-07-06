//implementation of finding divisors of any number

/* This algorithm is the most efficient of finding divisors of any numbers

Time Complexity: O(√n)
Space Complexity:O(k)

n=given number
k=constant space
*/

#include<bits/stdc++.h>
using namespace std;

void divisors(set<int>s,int n) //using set so divisors are in sorted way and are unique
{   
    int sqr=sqrt(n)+1;
    for(int i=1;i<=sqr;i++)
    {    
        int r=n%i;
        int q=n/i;
        if(r==0)
        {
            s.insert(i);
            s.insert(q);
        }
        
    }
}
// the set s will held all the divisors of n