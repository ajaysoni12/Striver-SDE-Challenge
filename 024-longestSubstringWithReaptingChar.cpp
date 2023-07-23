#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input)
{
    int left = 0, right = 0;
    int maxLen = 0;
    unordered_map<int, int> mp;
    int j = 0;
    for (int i = 0; i < input.size(); i++)
    {
        mp[input[i]]++;

        while (mp[input[i]] == 2)
        {
            mp[input[j]]--;
            j++;
        }

        maxLen = max(maxLen, i - j + 1);
    }
    return maxLen;
}