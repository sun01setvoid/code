#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ull unsigned long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e6 + 5;
const int mod = 998244353;
const ld eps = 1e-8;
//-----------------------------------------------------//
int dist[maxn], rdist[maxn];
bool st[maxn];
int n, m;
vector<vector<pii>> g(maxn);
void dij()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
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
        for (auto [v, w] : g[u])
        {
            if (!st[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}
void dij1()
{
    memset(rdist, 0x3f, sizeof rdist);
    memset(st, 0, sizeof st);
    rdist[n] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, n});
    while (q.size())
    {
        auto [dis, u] = q.top();
        q.pop();
        if (st[u])
            continue;
        st[u] = 1;
        for (auto [v, w] : g[u])
        {
            if (!st[v] && rdist[v] > rdist[u] + w)
            {
                rdist[v] = rdist[u] + w;
                q.push({rdist[v], v});
            }
        }
    }
}
vector<pii> ed(maxn);
void solve()
{
    int q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
        ed[i] = {u, v};
    }
    dij();
    dij1();
    for (int i = 1; i <= q; i++)
    {
        int t, x;
        cin >> t >> x;
        auto [u, v] = ed[t];
        cout << min({dist[n],dist[u] + rdist[v] + x, dist[v] + rdist[u] + x}) << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}