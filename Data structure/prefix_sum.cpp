//implementation of prefix_sum

/* Prefix sum is a pre-calculation data structure to complete queries in between ranges of
an array if the query function(sum,count,position) is inversible and there is no update in the array

Time Complexity: O(n)
Space Complexity:O(n)

n=total number of elements of array
*/

#include<bits/stdc++.h>
using namespace std;

void prefix_sum(int n,int i_array[],int presum_array[])
{
    presum_array[0]=i_array[0];
    for(int i=1;i<=n;i++)
    {
       presum_array[i]+=presum_array[i-1]+i_array[i];
    }
}