//implementation of sparse table

/* Sparse table is a pre-calculation data structure to complete queries in between ranges of
an array if the query function (gcd,min,max,sum) is not even inversible and there is no update in the array

Time Complexity: O(nlog(n))
Space Complexity:O(30*n)

n=total number of elements of array
*/

#include<bits/stdc++.h>
using namespace std;

struct 
{     
      //initializing sparse_table
      void init(int n,int k, int v[],int a[][30])         // n=total number of elements of array
      {                                                  //  k=floor(log2(n))
      for(int i=0;i<n;i++)                              //   30 will cover upto 1e9 number of elements,for counting more 
         {                                             //    one have to increase the number of columns of array a
            a[i][0]=v[i];
         }

      for(int j=1;j<=k;j++)
      {
         for(int i=0;i+(1<<j)-1<n;i++)
         {
            a[i][j]=max(a[i][j-1],a[i+(1<<(j-1))][j-1]); //function will be here, either max,min,gcd,sum etc
         }
      }
      }
      //function to solve query
      int query(int l,int r,int a[][30])
      {
         int j=log2(r-l+1);
         int mx=max(a[l-1][j],a[r-(1<<j)][j]); //query function will be there either max,min or gcd or other functions
         return mx;                           // that allows overlapping
      }
}sparse_table;
