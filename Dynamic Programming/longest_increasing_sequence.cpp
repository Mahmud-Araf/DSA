// implementations of  longest increasing sequence using dynamic programming    

#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>&arr, int n)
{
    int dp[n]={};
    dp[0]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }

    return *max_element(dp,dp+n);
}

int main()
{
    vector<int> arr = {10,22,9,33,21,50,41,60};
    int n = arr.size();

    cout<<lis(arr,n)<<endl;
    return 0;
}