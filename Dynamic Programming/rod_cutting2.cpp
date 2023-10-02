// implementation of rod cutting algorithm using bottom-up dynamic programming

#include<bits/stdc++.h>
using namespace std;    


int rodCutting(vector<int>& prices, int length, vector<int>&dp) {
    
    dp[0] = 0;

    for (int len = 1; len <= length; len++) {
        for (int cut = 1; cut <= len; cut++) {
            int revenue = prices[cut] + dp[len - cut];
            dp[len] = max(dp[len], revenue);
        }
    }

    return dp[length];
}

int main()
{
    vector<int> prices = {1 , 5 , 8 , 9, 10, 17, 17, 20, 24, 30, 32, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

    vector<int>dp(26,-1);

    cout<<rodCutting(prices,25,dp)<<endl;
}