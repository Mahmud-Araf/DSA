//implementation of counting sort algorithm

/* Counting sort is a fast sorting algorithm to sort array where all the elements 
of the array is in a certain range. It is a non comparison based algorithm 
and is not an in-place sort.

Time Complexity: O(n+k)
Space Complexity:O(n+k)

n=total number of elements of array
k=range
*/

#include<bits/stdc++.h>
using namespace std;

void counting_sort(int n,int k,int arr[])
{
    int out[n];
    int count[k+1];

    memset(count,0,sizeof(count));

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++)
    {
        count[i]+=count[i-1];
    }
    
    //for stable sort
    for(int i=n-1;i>=0;i--)
    {
       out[count[arr[i]]-1]=arr[i];
       count[arr[i]]--;
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=out[i];
    }
}

int main()
{
    int arr[]={8,3,0,2,1};

    counting_sort(5,8,arr);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


