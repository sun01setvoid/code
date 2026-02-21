//P3505 POI 2010
//图论计数
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
//-----------------------------------------------------//
vector<vii> g(maxn);
int dist[maxn];
bool st[maxn];
void dij()
{
    dist[1] = 0;
    dist[2] = 250;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while (q.size())
    {
        auto &[dis, u] = q.top();
        q.pop();
        if (st[u])
            continue;
        st[u] = 1;
        for (auto &v : g[u])
        {
            if (!st[v] && dist[v] > dist[u] + 60)
            {
                dist[v] = dist[u] + 60;
                q.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dij();
    if (dist[2] < 250)
    {
        cout << 0 << endl;
        return;
    }
    int c1 = 1, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 1;
    vii tmp;
    vector<bool> vis(maxn);
    vis[1] = 1, vis[2] = 1;
    for (auto v : g[1])
    {
        tmp.pb(v);
        vis[v] = 1;
        c2++;
    }
    for (auto x : tmp)
    {
        for (auto v : g[x])
        {
            if (!vis[v])
                c3++, vis[v] = 1;
        }
    }
    tmp.clear();
    for (auto v : g[2])
    {
        tmp.pb(v);
        vis[v] = 1;
        c5++;
    }
    for (auto x : tmp)
    {
        for (auto v : g[x])
        {
            if (!vis[v])
                c4++, vis[v] = 1;
        }
    }
    int d = n - c1 - c2 - c3 - c4 - c5 - c6;
    if (c2>=c5) c3+=d;
    else c4+=d;
    int ans = -m + c1 * c2 + c2 * (c2 - 1) / 2 + c2 * c3 + c3 * (c3 - 1) / 2 + c3 * c4 + c4 * (c4 - 1) / 2 + c4 * c5 + c5 * (c5 - 1) / 2 + c5 * c6;
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