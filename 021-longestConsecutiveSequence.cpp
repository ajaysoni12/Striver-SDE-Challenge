#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_set<int> set;

    int longest = 1;
    if (n == 0)
        return 0;

    for (int i = 0; i < n; i++)
        set.insert(arr[i]);

    for (auto it : set)
    {
        if (set.find(it - 1) == set.end())
        {
            int cnt = 1;
            int x = it;
            while (set.find(x + 1) != set.end())
            {
                cnt++;
                x = x + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}