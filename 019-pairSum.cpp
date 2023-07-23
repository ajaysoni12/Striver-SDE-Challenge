#include <bits/stdc++.h>
using namespace std; 

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int req = s - arr[i];
        if (mp.find(req) != mp.end())
        {
            for (int j = 0; j < mp[req]; j++)
            {
                if (arr[i] < req)
                    ans.push_back({arr[i], req});
                else
                    ans.push_back({req, arr[i]});
            }
        }
        mp[arr[i]]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}