// implementation of rod cutting algorithm using top-down dynamic programming

#include<bits/stdc++.h>
using namespace std;    


int rodCutting(vector<int>& prices, int len, vector<int>&dp) {
    if (len <= 0) {
        return 0;
    }

    if (dp[len] != -1) {
        return dp[len];
    }

    int maxRevenue = INT_MIN;

    for (int i = 1; i <= len; i++) {
        int revenue = prices[i] + rodCutting(prices, len - i,dp);
        maxRevenue = max(maxRevenue, revenue);
    }

    dp[len] = maxRevenue;
    return maxRevenue;
}

int main()
{
    vector<int> prices = {1 , 5 , 8 , 9, 10, 17, 17, 20, 24, 30, 32, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

    vector<int>dp(26,-1);

    cout<<rodCutting(prices,25,dp)<<endl;
}