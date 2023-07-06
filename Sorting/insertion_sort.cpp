//implementation of insertion sort algorithm

/* Insertion sort algorithm is used to sort a data structure.

Time Complexity: O(n^2)
Space Complexity:O(k)

n=total number of elements of array
k=constant space
*/

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int n,int arr[])
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        
        for(;j>=0 && arr[j]>key;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}

int main()
{
    int arr[]={10,-4,2,5,100,11,-2,0};

    insertion_sort(8,arr);

    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
