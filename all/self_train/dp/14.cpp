// 1064 金明的预算方案

//看错了，实际上只有对于每个主件，只有五种情况
//实际我这代码应该会超时
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

void solve()
{
    // 调整背包容量
    int n, m;
    cin >> n >> m;
    n = n / 10;
    vector<pii> a(m + 1);
    vector<vector<pii>> ac(m + 1);
    vector<bool> vis(m + 1, 0);
    rep(i, 1, m)
    {
        int v, p, q;
        cin >> v >> p >> q;
        if (q == 0)
            vis[i] = 1, a[i] = {v / 10, v / 10 * p};
        else
            ac[q].pb({v / 10, v / 10 * p});
    }
    vector<vii> con(m + 1, vii(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        if (vis[i])
        {
            for (int j = 0; j < ac[i].size(); j++)
            {
                for (int k = n; k >= ac[i][j].fi; k--)
                    con[i][k] = max(con[i][k], con[i][k - ac[i][j].fi] + ac[i][j].se);
            }
        }
    }
    vii dp(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i])
            continue;
        for (int j = n; j >= a[i].fi; j--)
        {
            int vol = a[i].fi, val = a[i].se;
            for (int k = 0; k <= j - vol; k++)
            {
                dp[j]=max(dp[j],dp[j-vol-k]+con[i][k]+a[i].se);
            }
        }
    }
    cout << dp[n] * 10 << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}