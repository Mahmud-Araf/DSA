// implementation of invertion counting using merge sort
#include<bits/stdc++.h>
using namespace std;

int32_t merge(vector<int>&v,int left,int mid,int right) // merges left and right vectors
{
    int l1=mid-left+1;
    int l2=right-mid;
    int inversion=0;


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
          inversion+=l1-indx1;
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

    return inversion;
}

int merge_sort(vector<int>&v,int begin,int end) 
{
   if(begin>=end)
   {
      return 0;
   }
   int inversion=0;
   int mid=begin+(end-begin)/2;
   inversion+=merge_sort(v,begin,mid);
   inversion+=merge_sort(v,mid+1,end);
   inversion+=merge(v,begin,mid,end);

   return inversion;
}


int main()
{
    vector<int>v={2,4,3,1};
    cout<<merge_sort(v,0,3)<<endl;
}