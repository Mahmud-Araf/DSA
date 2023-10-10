// implementation of matrix chain multiplication of matrices using dynamic arrrogramming top-down

#include<bits/stdc++.h>
using namespace std;
int matrixChain(vector<int>& arr, int i, int j, vector<vector<int>>& dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], matrixChain(arr, i, k, dp) + matrixChain(arr, k + 1, j, dp)
            + arr[i - 1] * arr[k] * arr[j]);
    }
    return dp[i][j];
}

int matrixChainMultiplication(vector<int>& arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return matrixChain(arr, 1, n - 1, dp);
}

int main()
{
    vector<int> dimensions = {1, 2, 3, 4, 3 };
    int result = matrixChainMultiplication(dimensions);
    cout << "Minimum number of multiplications: " << result << endl;
    return 0;
}
