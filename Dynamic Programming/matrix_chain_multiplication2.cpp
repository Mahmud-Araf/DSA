// implementation of matrix chain multiplication of matrices using dynamic arrrogramming bottom-up

#include<bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int>& arr) {
    int n = arr.size();
    
    // Create dp table to store minimum multiplication counts
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    // Set the base case where the cost of multiplying a single matrix is 0
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // Loop for chain length 'len' from 2 to n
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    return dp[1][n - 1];
}

int main() {
    vector<int> dimensions = {1, 2, 3, 4, 3};
    int result = matrixChainMultiplication(dimensions);
    
    cout << "Minimum number of multiplications: " << result << endl;
    
    return 0;
}
