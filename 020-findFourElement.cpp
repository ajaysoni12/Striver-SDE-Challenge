#include <bits/stdc++.h>
using namespace std;

string fourSum(vector<int> arr, int target, int n)
{
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int low = j + 1, high = n - 1;
            while (low < high)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[low];
                sum += arr[high];

                if (sum == target)
                    return "Yes";
                else if (sum < target)
                    low++;
                else
                    high--;
            }
        }
    }
    return "No";
}