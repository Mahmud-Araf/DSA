//implementation of bubble sort algorithm

/* Bubble sort algorithm is used to sort a data structure.

Time Complexity: O(n^2)
Space Complexity:O(k)

n=total number of elements of array
k=constant space
*/

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int n,int arr[])
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }
}

int main()
{
    int arr[]={10,-4,2,5,100,11,-2,0};

    bubble_sort(8,arr);

    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}