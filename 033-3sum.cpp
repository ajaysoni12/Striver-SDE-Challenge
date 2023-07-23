#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approch: generate all triplets) */
vector<vector<int>> triplets(vector<int> &nums, int n)
{
    // for storing unique ele
    set<vector<int>> set;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end()); // for removing duplicacy
                    set.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(set.begin(), set.end());
    return ans;
    /*  TC-O(n*n*n*log(unique)) = n^3 * Log(uniqueEle)))
        SC-O(2*noOf triplets) */
}

/* method 2 (better solution: using hashing) */
vector<vector<int>> triplets(vector<int> &nums, int n)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end()); // for removing duplicacy
                st.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    /*  TC-O(n*n*log(unique)) = n^2 * Log(uniqueEle)))
        SC-O(n) + O(noOfUnique*2) */
}

/* using sorting */
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        int target = K - arr[i];
        int front = i + 1;
        int back = n - 1;

        while (front < back)
        {
            int sum = arr[front] + arr[back];
            if (sum < target)
                front++;
            else if (sum > target)
                back--;
            else
            {
                ans.push_back({arr[i], arr[front], arr[back]});
                int x = arr[front];
                int y = arr[back];

                while (front < back && arr[front] == x)
                    front++;
                while (front < back && arr[back] == y)
                    back--;
            }
        }
        while (i + 1 < n && arr[i] == arr[i + 1])
            i++;
    }
    return ans;
}