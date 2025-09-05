#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, m, k;
int lowbit(int x)
{
    return x & -x;
}
map<int, int> pos;
void solve()
{
    cin >> n >> m >> k;
    k = min(m, k);
    vector<vii> mp(n + 1, vii(m + 1));
    vii dp(1 << m, 0), f(1 << m, 0), g(1 << m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        g[0] = 0;
        for (int j = 1; j < (1 << m); j++) // 状态转移
        {
            g[j] = g[j ^ lowbit(j)] + mp[i][pos[lowbit(j)]];
            f[j] = max(f[j], g[j]);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int s = (1 << m) - 1; s >= 1; s--)
        {
            for (int t = s; t > 0; t = (t - 1) & s)
            {
                dp[s] = max(dp[s], dp[s ^ t] + f[t]);
            }
        }
    }
    cout << dp[(1 << m) - 1] << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    for (int i = 0; i <= 12; i++)
        pos[1 << i] = i;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}