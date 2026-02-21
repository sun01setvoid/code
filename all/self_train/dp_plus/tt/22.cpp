//神秘的无语........
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[maxn];
int q[maxn], q1[maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vii a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans += a[i];
    dp[0] = 0;
    int hh = 0, tt = -1;
    q[++tt] = 0;
    q1[tt] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (hh <= tt && q[hh] < i - m - 1)
            hh++;
        dp[i] = q1[hh] + a[i];
        while (hh <= tt && q1[tt] > dp[i])
            tt--;
        q[++tt] = i;
        q1[tt] = dp[i];
    }
    int res = inf;
    for (int i = n; i >= max(n - m, 0ll); i--)
        res = min(res, dp[i]);
    cout << ans - res << endl;
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