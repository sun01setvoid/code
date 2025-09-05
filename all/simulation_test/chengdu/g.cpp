#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> mp;
    for (int &x : a)
    {
        cin >> x;
        mp.insert(x);
    }
    for (int i = 1; i < n; i++)
    {
        mp.insert(a[i - 1] ^ a[i]);
        mp.insert(a[i - 1] & a[i]);
        mp.insert(a[i - 1] | a[i]);
        mp.insert(a[i-1]^(a[i-1]&a[i]));
        mp.insert(a[i]^(a[i-1]&a[i]));
        mp.insert(a[i-1]^(a[i-1]|a[i]));
        mp.insert(a[i]^(a[i-1]|a[i]));
    }
    cout << mp.size();
}