// implementations of longest increasing subsequence using  binary search 

#include<bits/stdc++.h>
using namespace std;


int lis(vector<int>&arr,int n)
{
   vector<int>ans;

   ans.push_back(arr[0]);

   for(int i=1;i<n;i++)
   {
         if(arr[i]>ans.back())
         {
            ans.push_back(arr[i]);
         }
         else
         {
            int low = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[low]=arr[i];
         }     
   }

   return ans.size();
}

int main()
{
    vector<int> arr ={9, 2, 5 , 3, 7, 11, 8, 10, 13, 6};
    int n = arr.size();

    cout<<lis(arr,n)<<endl;
    return 0;
}