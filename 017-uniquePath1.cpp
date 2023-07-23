#include <bits/stdc++.h>
using namespace std; 


int f(int m, int n, vector<vector<int>> &dp)
{
    if (m == 1 && n == 1)
        return 1;
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    // left - right
    int left = f(m, n - 1, dp);
    // up - down
    int right = f(m - 1, n, dp);
    return dp[m][n] = (left + right);
}
int uniquePaths(int m, int n)
{
    // vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    // return f(m, n, dp);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    dp[1][1] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;

            int left = 0, right = 0;
            // left - right
            left = dp[i][j - 1];
            // up - down
            right = dp[i - 1][j];
            dp[i][j] = (left + right);
        }
    }

    return dp[m][n];
}