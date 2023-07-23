#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int start, int mid, int end)
{
    vector<long long> temp;
    int left = start, right = mid + 1;
    long long cnt = 0;

    while (left <= mid && right <= end)
    {

        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= end)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = start; i <= end; i++)
        arr[i] = temp[i - start];
    return cnt;
}
long long mergeSort(long long *arr, int start, int end)
{
    long long cnt = 0;
    if (start >= end)
        return cnt;

    int mid = (start + end) / 2;
    cnt += mergeSort(arr, start, mid);
    cnt += mergeSort(arr, mid + 1, end);
    cnt += merge(arr, start, mid, end);
    return cnt;
}
long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}