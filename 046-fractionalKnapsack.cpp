#include <bits/stdc++.h>
using namespace std; 

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;

    return r1 > r2;
}
double maximumValue(vector<pair<int, int>> &items, int n, int W)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), cmp);

    int currWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + items[i].first <= W)
        {
            currWeight += items[i].first;
            finalValue += items[i].second;
        }
        else
        { // take fracktion weight
            int remain = W - currWeight;
            finalValue += (items[i].second / (double)items[i].first) * (double)remain;
            break;
        }
    }
    return finalValue;
}