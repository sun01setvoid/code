#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
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
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int f1[maxn][10], f2[maxn][10];
int c1[maxn][10], c2[maxn][10];
int n, k;
vector<vii> adj(maxn);
void dfs1(int u, int fa)
{
    c1[u][0] = 1;
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        dfs1(v, u);
        for (int j = 1; j <= k; j++)
        {
            c1[u][j % k] += c1[v][j - 1];
            f1[u][j % k] += f1[v][j - 1];
            if (j == 1)
                f1[u][j % k] += c1[v][j - 1];
        }
    }
}
void dfs2(int u, int fa)
{
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        for (int j = 1; j <= k; j++)
        {
            // debug(v);
            // debug(j);
            c2[v][j % k] += c2[u][j - 1] + c1[u][j - 1] - c1[v][((j - 2) % k + k) % k];
            f2[v][j % k] += f2[u][j - 1];
            if (j == 1)
                c2[v][j % k]--;
            if (j == 1)
                f2[v][j % k] += c2[u][j - 1];
            // debug(f2[v][j % k]);
            int res = f1[u][j - 1] - f1[v][((j - 2) % k + k) % k];
            // debug(res);
            if (((j - 2) % k + k) % k == 0)
                res -= c1[v][0];
            f2[v][j % k] += res;
            // debug(res);
            // debug(f2[v][j % k]);
            if (j == 1)
                f2[v][j % k] += c1[u][j - 1] - 1 - c1[v][((j - 2) % k + k) % k];
            // debug(c1[u][j - 1] - 1);
            // debug(c1[v][((j - 2) % k) % k]);
            // debug(f1[v][j % k]);
        }
        dfs2(v, u);
    }
}
int sz[maxn], ans;
void dfs3(int u, int fa)
{
    sz[u] = 1;
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        dfs3(v, u);
        sz[u] += sz[v];
        ans += sz[v] * (n - sz[v]);
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans = 0;
    // if (k == 1)
    // {
    //     dfs3(1, 0);
    //     cout << ans << endl;
    //     return;
    // }
    dfs1(1, 0);
    dfs2(1, 0);
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            ans1 += f1[i][j];
            ans2 += f2[i][j];
        }
    }
    cout << ans1 + ans2 / 2 << endl;
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