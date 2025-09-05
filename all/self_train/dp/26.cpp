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
const int maxn = 3e3 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, m;
vector<vector<pii>> adj(maxn);
int a[maxn];
int dp[maxn][maxn];
int sz[maxn];
void dfs(int u, int fa)
{
    dp[u][0] = 0;
    sz[u] = 1;
    for (auto &v : adj[u])
    {
        int cur = v.fi, w = v.se;
        if (cur == fa)
            continue;
        dfs(cur, u);
        vii tmp(sz[u] + sz[cur] + 1, INF);//也滚动数组滚一下
        tmp[0] = 0;
        for (int j = 0; j <= sz[u]; j++)  //这样的话只有lca时会更新，所以只有O(n^2)
        {
            for (int i = 0; i <= sz[cur]; i++)
            {
                tmp[j + i] = min(tmp[j + i], dp[u][j] + dp[cur][i] + w);
            }
        }
        sz[u] += sz[cur];
        for (int j = 0; j <= sz[u]; j++)
        {
            dp[u][j] = min(dp[u][j],tmp[j]);
        }
    }
}
void solve()
{
    cin >> n >> m;
    rep(i, 1, n - m)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int v, c;
            cin >> v >> c;
            adj[i].eb(v, c);
            adj[v].eb(i, c);
        }
    }
    rep(i, 1, n) rep(j, 1, m) dp[i][j] = INF;
    rep(i, n - m + 1, n) cin >> a[i], dp[i][1] = -a[i];
    dfs(1, 0);
    int ans = 0;
    drep(i, m, 1)
    {
        if (dp[1][i] <= 0)
        {
            ans = max(i, ans);
        }
    }
    cout << ans << endl;
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