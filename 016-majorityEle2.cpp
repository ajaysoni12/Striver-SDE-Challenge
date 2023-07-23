#include <bits/stdc++.h>
using namespace std; 

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;
    int ele1 = -1, ele2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && arr[i] != ele2)
        {
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if (cnt2 == 0 && arr[i] != ele1)
        {
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if (arr[i] == ele1)
        {
            cnt1++;
        }
        else if (arr[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--, cnt2--;
        }
    }

    int freq1 = 0, freq2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
            freq1++;
        else if (arr[i] == ele2)
        {
            freq2++;
        }
    }

    vector<int> ans;
    if (freq1 > n / 3)
        ans.push_back(ele1);
    if (freq2 > n / 3)
        ans.push_back(ele2);

    sort(ans.begin(), ans.end());
    return ans;
}