#include <bits/stdc++.h>
using namespace std; 

/* method 1 (using two loops) */
/* method 2 (hashing) */

/* method 3 */
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int reapting, missing;

    for (int i = 0; i < n; i++)
    {
        int ind = abs(arr[i]);
        if (arr[ind - 1] < 0)
        {
            reapting = ind;
        }
        else
        {
            arr[ind - 1] = -arr[ind - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            missing = i + 1;
            break;
        }
    }
    pair<int, int> ans = {missing, reapting};
    return ans;
}
