// P6961
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
vector<vector<array<int, 3>>> g(maxn);
vector<array<int, 3>> ed;
int n, m, k;
int dist[maxn];
bool st[maxn];
void dij(int mid)
{
    for (int u = 1; u <= n; u++)
    {
        for (auto &[v, w, d] : g[u])
        {
            if (w > mid)
                d = w - mid;
            else
                d = 0;
        }
    }
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while (q.size())
    {
        auto [dis, u] = q.top();
        q.pop(); // 因为pop了，所以不要引用
        if (st[u])
            continue;
        st[u] = 1;
        for (auto &[v, w, d] : g[u])
        {
            if (!st[v] && dist[v] > dist[u] + d)
            {
                dist[v] = dist[u] + d;
                q.push({dist[v], v});
            }
        }
    }
}
int to[maxn];
void dij()
{
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while (q.size())
    {
        auto [dis, u] = q.top();
        q.pop();
        if (st[u])
            continue;
        st[u] = 1;
        for (auto &[v, w, d] : g[u])
        {
            if (!st[v] && dist[v] > dist[u] + d)
            {
                dist[v] = dist[u] + d;
                to[v] = to[u] + 1;
                q.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w, w});
        g[v].pb({u, w, w});
        ed.pb({u, v, w});
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = inf;
    }
    dij();
    if (to[n] <= k)
    {
        ans = dist[n];
    }
    for (auto &[u, v, w] : ed)
    {
        for (int i = 1; i <= n; i++)
            dist[i] = inf, st[i] = 0;
        dij(w);
        ans = min(ans, dist[n] + k * w);
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