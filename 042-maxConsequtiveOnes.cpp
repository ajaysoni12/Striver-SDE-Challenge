#include <bits/stdc++.h>
using namespace std;

/* window sliding method */
int longestSubSeg(vector<int> &arr, int n, int k)
{
    int ans = 0;

    int low = 0, high = 0;
    int cnt0 = 0;
    while (high < n)
    {
        while (high < n && cnt0 <= k)
        {
            if (arr[high] == 0)
                cnt0++;

            if (cnt0 > k)
                break;

            high++;
        }

        ans = max(ans, high - low);

        while (low <= high && cnt0 > k)
        {
            if (arr[low] == 0)
                cnt0--;

            if (cnt0 <= k)
                break;

            low++;
        }
        low++;
        high++;
    }
    return ans;
    /*  TC-O(n) SC-O(n) */
}