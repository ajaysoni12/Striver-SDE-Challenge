#include <bits/stdc++.h>
using namespace std;

/* method 1 (sorting) */
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1,
                                 vector<int> &arr2, int m, int n)
{

    int i = m - 1;
    int j = 0;

    while (i >= 0 && j < n && arr1[i] > arr2[j])
    {
        swap(arr1[i], arr2[j]);
        i--;
        j++;
    }

    sort(arr1.begin(), arr1.begin() + m);
    sort(arr2.begin(), arr2.end());

    for (int i = m; i < m + n; i++)
        arr1[i] = arr2[i - m];
    return arr1;
}

// optimize 
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int i = m - 1;
    int j = n - 1;
    int li = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && arr1[i] > arr2[j])
        {
            arr1[li] = arr1[i];
            i--;
        }
        else
        {
            arr1[li] = arr2[j];
            j--;
        }
        li--;
    }
    return arr1;
}