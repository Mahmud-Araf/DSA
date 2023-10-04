#include <bits/stdc++.h>
using namespace std;

int minimum_path_sum(vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                if (j >= 1 and j + 1 <= n - 1)
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
                else if (j - 1 < 0 and j + 1 >= n)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else if (j - 1 < 0)
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                else
                {
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }
    }

    int minCost = INT_MAX;

    for (int j = 0; j < n; j++)
    {

        minCost = min(minCost, dp[m - 1][j]);
    }

    return minCost;
}

int findMinLevel(vector<vector<int>> &dp, int i, int j, int m, int n)
{

    if (j < n - 1 && j > 0)
    {
        if (dp[i - 1][j - 1] >= dp[i - 1][j] && dp[i - 1][j] <= dp[i - 1][j + 1])
        {
            return j;
        }
        else if (dp[i - 1][j - 1] <= dp[i - 1][j] && dp[i - 1][j] <= dp[i - 1][j + 1])
        {
            return j - 1;
        }
        else
        {
            return j + 1;
        }
    }
    else if(j==n-1)
    {
        if(dp[i-1][j]<=dp[i-1][j -1])
        return j;
        else
        return j-1;
    }
    else
    {
        if(dp[i-1][j]<=dp[i-1][j+1])
        return j;
        else
        return j+1;
    }
      
}

void printPath(vector<vector<int>> &dp, vector<vector<int>> &grid, int m, int n, int minCost)
{

    vector<int> path;

    int i = m - 1;

    int j;

    for (int it = 0; it < n; it++)
    {
        if (dp[m - 1][it] == minCost)
        {
            j = it;
            break;
        }
    }

    while (i >= 0)
    {
        path.push_back(grid[i][j]);

        if(i!=0)
         j = findMinLevel(dp, i, j,m,n);

        i--;
    }

    reverse(path.begin(), path.end());

    cout<<"The path is:"<<endl;

    for (int a : path)
    {
        cout << a << endl;
    }
}

int main()
{

    int m = 4, n = 5;

    vector<vector<int>> grid = {
        {3, 2, 5, 4, 8},
        {5, 7, 5, 6, 1},
        {4, 4, 6, 2, 3},
        {2, 8, 9, 5, 8}};

    vector<vector<int>> dp(4, vector<int>(4));

    int ans = minimum_path_sum(grid, dp, m, n);

    cout << ans << endl;

    printPath(dp, grid, m, n, ans);

    return 0;
}