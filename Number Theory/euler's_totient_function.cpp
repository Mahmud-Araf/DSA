//implementation of euler's totient/phi function

/* Euler's phi function of n counts the positive integers up to n which are relatively prime to n.

Time Complexity: O(log(n))
Space Complexity:O(k)

n=given number
k=constant space
*/

#include<bits/stdc++.h>
using namespace std;

int phi_function(int n)
{
   int result=n;
   int temp=n;
   for(int i=2;i*i<=n;i++)
   {
      if(temp%i==0)
      {
         while(temp%i==0)
         {
            temp/=i;
         }
         result*=(1.0-(1.0/(double)i));
        
      }
   }
  
   if(temp>1)
   {
      result*=(1.0-((1.0/(double)temp)));
      return result;
   }
   else
   return result;
}