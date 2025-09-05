#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, m;
void solve()
{
    cin>>n>>m;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        sum += x;
        a[i] = x - y;
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    int idx = 0;
    for (int i = n; i >= 1; i--)
    {
        if (sum <= m)
            break;
        sum -= a[i], idx++;
    }
    if (sum <= m)
        cout << idx;
    else
        cout << -1;
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}