// implementations of  longest increasing sequence using dynamic programming    

#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>&arr, int n)
{
    vector<int>dp(n),parent(n);

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1; 
        parent[i]=-1;
    }



    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                parent[i]=j;
            }
        }
    }

    int it = max_element(dp.begin(), dp.end())- dp.begin();

    int max = dp[it];
    
    vector<int>ans;

    while(it!=-1)
    {
        ans.push_back(arr[it]);

        it = parent[it];

    }

    reverse(ans.begin(),ans.end());

    for(auto i:ans)
    {
        cout<<i<<" ";
    }

    cout<<endl;

    return max;


}

int main()
{
    vector<int> arr = {9, 2, 5 , 3, 7, 11, 8, 10, 13, 6};
    int n = arr.size();

    cout << lis(arr, n) << endl;
    return 0;
}
