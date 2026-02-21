//5590赛车
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define pb push_back
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------/
vector<vector<pii>> g(maxn);
vector<vii> rg(maxn), ng(maxn);
bool vis[maxn];
int to[maxn], dist[maxn];
bool st1[maxn], st2[maxn];
vector<pii> ed;
// 首先确定取值范围,然后看用最短路，还是最长路，这样就知道超级源点怎么连
// 最短路和最长路不要用混，不然会无解
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v].pb({u, -9});
        g[u].pb({v, 1});
        rg[u].pb(v); // 对边做限制，看看有没有解
        ng[v].pb(u);
        ed.pb({u, v});
    }
    // 至于这个相等，其实只要跑出来就可以了，就是有一组解呗
    queue<int> q;
    st1[1] = 1;
    q.push(1);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : rg[u])
        {
            if (!st1[v])
                st1[v] = 1, q.push(v);
        }
    }
    st2[n] = 1;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : ng[u])
        {
            if (!st2[v])
                st2[v] = 1, q.push(v);
        }
    }
    if (!st1[n])
    {
        cout << -1 << endl;
        return;
    }
    dist[0] = 0;
    for (int i = 1; i <= n; i++)
        g[0].pb({i, 0}), dist[i] = -inf;
    st1[0] = 1;
    q.push(0);
    vis[0] = 1;
    bool f = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        if (to[u] > n)
        {
            debug(1);
            f = 0;
            break;
        }
        for (auto [v, w] : g[u])
        {
            if (st1[u] && st2[v])
            {
                if (dist[v] < dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    to[v] = to[u] + 1;
                    if (!vis[v])
                        q.push(v), vis[v] = 1;
                }
            }
        }
    }
    if (!f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << n << " " << m << endl;
        for (auto &[u, v] : ed)
        {
            if (st1[u] && st2[v])
                cout << u << " " << v << " " << dist[v] - dist[u] << endl;
            else
                cout << u << " " << v << " " << 1 << endl;
        }
    }
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