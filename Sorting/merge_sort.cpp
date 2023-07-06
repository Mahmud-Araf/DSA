//implementation of merge sort

/* Merge sort is fast stable sorting algorithm but it's not an in-place sorting algorithm

Time Complexity: O(nlogn)
Space Complexity:O(n)

n=total number of elements of array
*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v,int left,int mid,int right) // merges left and right vectors
{
    int l1=mid-left+1;
    int l2=right-mid;

    vector<int>v1(l1),v2(l2);

    for(int i=0;i<l1;i++)
    {
      v1[i]=v[left+i];
    }

    for(int i=0;i<l2;i++)
    {
      v2[i]=v[mid+1+i];
    }

    int indx=left;
    int indx1=0;
    int indx2=0;

    while(indx1<l1 && indx2<l2)
    {
        if(v1[indx1]<=v2[indx2])
        {
          v[indx]=v1[indx1];
          indx1++;
        }
        else
        {
          v[indx]=v2[indx2];
          indx2++;
        }
        indx++;
    }

    while(indx1<l1)
    {
      v[indx]=v1[indx1];
      indx++;
      indx1++;
    }
    while(indx2<l2)
    {
      v[indx]=v2[indx2];
      indx++;
      indx2++;
    }
}

void merge_sort(vector<int>&v,int begin,int end) // for sorting whole vector begin will be 0 and end will be n-1
{
   if(begin>=end)
   {
      return;
   }

   int mid=begin+(end-begin)/2;
   merge_sort(v,begin,mid);
   merge_sort(v,mid+1,end);
   merge(v,begin,mid,end);
}

int main()
{
    vector<int> arr={10,-4,2,5,100,11,-2,0};

    merge_sort(arr,0,7);

    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
