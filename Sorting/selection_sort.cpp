//implementation of selection sort algorithm

/* Selection sort algorithm is used to sort a data structure.

Time Complexity: O(n^2)
Space Complexity:O(k)

n=total number of elements of array
k=constant space
*/

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int n,int arr[])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main()
{
    int arr[]={10,-4,2,5,100,11,-2,0};

    selection_sort(8,arr);

    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}