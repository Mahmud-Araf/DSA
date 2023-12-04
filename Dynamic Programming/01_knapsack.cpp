// implementation of 0/1 knapsack using dynamic programming

#include<bits/stdc++.h>
using namespace std;

int knapsack(int Weight, vector<int>& wt, vector<int>& profit, int n)
{
    int i, w;
    vector<vector<int>> dp(n + 1, vector<int>(Weight + 1));

    for (i = 0; i <= n; i++)
    {
        for (int w = 0; w <= Weight; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][Weight];
}

int main()
{
    vector<int> profit = {2, 3, 1, 4};
    vector<int> wt = {3,4,6,5};
    int Weight = 8;
    int n = 4;

    int maxProfit = knapsack(Weight, wt, profit, n);
    cout << "Maximum profit: " << maxProfit << endl;
}
