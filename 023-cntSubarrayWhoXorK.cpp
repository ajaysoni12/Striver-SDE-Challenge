#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int _xor = 0;
        for (int j = i; j < n; j++)
        {
            _xor ^= arr[j];
            if (_xor == x)
                cnt++;
        }
    }
    return cnt;
}