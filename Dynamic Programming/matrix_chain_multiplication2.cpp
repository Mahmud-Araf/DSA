// implementation of matrix chain multiplication of matrices using dynamic arrrogramming bottom-up
#include<bits/stdc++.h>
using namespace std;

int matrixChain(vector<int>& arr, int i, int j, vector<vector<int>>& dp, vector<vector<int>>& split)
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
    int minSplit = -1;
    
    for (int k = i; k < j; k++)
    {
        int cost = matrixChain(arr, i, k, dp, split) + matrixChain(arr, k + 1, j, dp, split)
            + arr[i - 1] * arr[k] * arr[j];
        
        if (cost < dp[i][j])
        {
            dp[i][j] = cost;
            minSplit = k;
        }
    }
    
    split[i][j] = minSplit;
    
    return dp[i][j];
}

void printOptimalOrder(vector<vector<int>>& split, int i, int j, char& matrixName)
{
    if (i == j)
    {
        cout << matrixName;
        matrixName++;
    }
    else
    {
        cout << "(";
        printOptimalOrder(split, i, split[i][j], matrixName);
        printOptimalOrder(split, split[i][j] + 1, j, matrixName);
        cout << ")";
    }
}

int matrixChainMultiplication(vector<int>& arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> split(n, vector<int>(n, -1));
    
    int result = matrixChain(arr, 1, n - 1, dp, split);
    
    char matrixName = 'A';
    cout << "Optimal Parentheses: ";
    printOptimalOrder(split, 1, n - 1, matrixName);
    cout << endl;
    
    return result;
}

int main()
{
    vector<int> dimensions = {1, 2, 3, 4, 3 };
    int result = matrixChainMultiplication(dimensions);
    cout << "Minimum number of multiplications: " << result << endl;
    return 0;
}
