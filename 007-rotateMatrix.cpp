#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int i = 0, j = 0;

    while (i < n - 1 - i && j < m - 1 - j)
    {
        int prev = mat[i][j];

        // right
        for (int k = j + 1; k <= m - 1 - j; k++)
        {
            swap(prev, mat[i][k]);
        }

        // down
        for (int k = i + 1; k <= n - 1 - i; k++)
        {
            swap(prev, mat[k][m - 1 - j]);
        }

        // left
        for (int k = m - 1 - j - 1; k >= j; k--)
        {
            swap(prev, mat[n - 1 - i][k]);
        }

        // up
        for (int k = n - 1 - i - 1; k >= i; k--)
        {
            swap(prev, mat[k][j]);
        }

        i++, j++;
    }
    /*  TC-O(n*n) SC-O(1) */
}