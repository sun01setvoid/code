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
#define eb emplace_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<vii> adj(maxn + 1);
int dist[maxn], f[maxn];
bool diam[maxn];
void dfs(int u, int fa)
{
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        dist[v] = dist[u] + 1;
        f[v] = u;
        dfs(v, u);
    }
}
void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) adj[i].clear(), diam[i] = 0;
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dist[1] = 0;
    dfs(1, -1);
    int st = -1, en = -1;
    for (int i = 1; i <= n; i++)
    {
        if (st == -1 || dist[i] > dist[st])
            st = i;
    }
    dist[st] = 0;
    dfs(st, -1);
    for (int i = 1; i <= n; i++)
    {
        if (en == -1 || dist[i] > dist[en])
            en = i;
    }
    diam[st] = 1;
    for (int i = en; i != st; i = f[i])
    {
        diam[i] = 1;
    }
    int a, b, c;
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto v : adj[i])
        {
            if (diam[i] && !diam[v])
            {
                flag = 1;
                a = f[i], b = i, c = v;
            }
        }
    }
    if (flag)
    {
        cout << a << " " << b << " " << c << endl;
    }
    else
        cout << -1 << endl;
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