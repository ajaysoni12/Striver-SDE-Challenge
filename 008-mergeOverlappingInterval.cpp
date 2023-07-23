#include <bits/stdc++.h>
using namespace std; 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int start = arr[0][0];
    int end = arr[0][1];

    vector<vector<int>> ans;
    ans.push_back({start, end});
    for (int i = 1; i < n; i++)
    {
        // cout << arr[i][0] << " " << arr[i][1] << endl;
        if (end >= arr[i][0])
        {
            ans[ans.size() - 1][1] = max(end, arr[i][1]);
            end = max(end, arr[i][1]);
        }
        else
        {
            start = arr[i][0];
            end = arr[i][1];
            ans.push_back({arr[i][0], arr[i][1]});
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}
