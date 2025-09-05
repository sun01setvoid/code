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
const int INF = 0x3f3f3f3f;
const int maxn = 5e3 + 10;
const int maxm = 5e5 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n, m;
vector<vii> G(maxn + 1);
void solve()
{

    cin >> n >> m;
    rep(i, 1, n) G[i].clear();
    vector<vii> dp(2 * n + 1, vii(n + 1, INF));
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dp[0][1] = 0;
    rep(i, 0, 2 * n - 1)
    {
        rep(j, 1, n) //dp顺序尽量和循环顺序一致，这样访问会更快，有时可省二分之一
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            int e = i % G[j].size();
            dp[i + 1][G[j][e]] = min(dp[i + 1][G[j][e]], dp[i][j]);
        }
    }
    rep(i, 1, 2 * n)
    {
        if (dp[i][n] != INF)
        {
            cout << i << " " << dp[i][n] << endl;
            return;
        }
    }
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}