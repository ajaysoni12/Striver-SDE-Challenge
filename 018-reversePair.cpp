#include <bits/stdc++.h>
using namespace std; 

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int start = low, right = mid + 1;

    while (start <= mid && right <= high)
    {
        if (arr[start] <= arr[right])
        {
            temp.push_back(arr[start]);
            start++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (start <= mid)
    {
        temp.push_back(arr[start]);
        start++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int cntPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;

        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += cntPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}
int reversePairs(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}