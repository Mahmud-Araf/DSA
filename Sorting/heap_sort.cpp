// implementation of heap sort using maxheap

#include<bits/stdc++.h>
using namespace std;

void maxheapify(int arr[],int n,int indx)
{
    int largest=indx;
    int left=2*indx+1;
    int right=2*indx+2;

    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }

    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }

    if(largest!=indx)
    {
        swap(arr[largest],arr[indx]);
        maxheapify(arr,n,largest);
    }
}

void heap_sort(int arr[],int n)//bottom up heap construction
{
    for(int i=n/2-1;i>=0;i--)
    {
        maxheapify(arr,n,i);
    }

    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        maxheapify(arr,i,0);
    }
}


int main()
{
    int arr[]={11,2,13,5,23,0,7};
    heap_sort(arr,7);
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}