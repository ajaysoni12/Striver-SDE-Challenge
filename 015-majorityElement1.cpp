#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    int freq = 0;
    int ele;

    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
            ele = arr[i];

        if (arr[i] == ele)
            freq++;
        else
            freq--;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
            cnt++;
    }
    if (cnt > n / 2)
        return ele;
    return -1;
}