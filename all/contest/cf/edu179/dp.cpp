#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    deque<pair<int, int>> dq;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        y = x / 100;
        dq.push_back({y, x});
    }
    sort(dq.begin(), dq.end());
    for (int i = 0; i < n; i++)
    {
        auto x = dq.front(), y = dq.back();
        if (x.second == y.second)
        {
            ans.push_back({y.second, y.second});
            if (ans.size() == n)
                break;
            dq.pop_back();
        }
        else
        {
            ans.push_back({x.second, y.second});
            if (ans.size() == n)
                break;
            ans.push_back({y.second, x.second});
            if (ans.size() == n)
                break;
            dq.pop_back();
            dq.pop_front();
        }
    }
    for (auto i : ans)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << i.first << " " << i.second << " ";
        }
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}