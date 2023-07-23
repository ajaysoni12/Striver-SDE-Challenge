#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size();
    unordered_map<long long, int> mp;

    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long req = sum;
        if (mp.find(req) != mp.end())
        {
            maxLen = max(maxLen, i - mp[req]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return maxLen;
}