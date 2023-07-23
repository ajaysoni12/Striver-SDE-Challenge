#include <bits/stdc++.h>
using namespace std;

int f(int x, int n, int m)
{
    if (n == 1)
        return x;
    long long ans = f(x, n / 2, m) % m;
    if (n % 2 == 0)
        ans = (ans * ans) % m;
    else
        ans = ((x * ans) % m * ans) % m;
    return (int)ans % m;
    /*  TC-O(log(n)) SC-O(log(n)) */
}
int modularExponentiation(int x, int n, int m)
{
    return f(x, n, m) % m;
}