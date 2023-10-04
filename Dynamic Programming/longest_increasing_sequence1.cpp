// implementations of  longest increasing sequence using dynamic programming    

#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>&arr, int n)
{
    int dp[n];
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1; 
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp, dp + n);
}

int main()
{
    vector<int> arr = {9, 2, 5 , 3, 7, 11, 8, 10, 13, 6};
    int n = arr.size();

    cout << lis(arr, n) << endl;
    return 0;
}
