// P3371 单源最短路（标准版）
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
const int inf = (1ll << 31) - 1;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dist[maxn];
bool st[maxn];
vector<vector<pii>> adj(maxn);
int n, m, s;
void dijikstra()
{
    fill(dist + 1, dist + n + 1, inf);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size())
    {
        auto cur = pq.top();
        int dis = cur.fi, u = cur.se;
        pq.pop();
        if (st[u])
            continue;
        st[u] = 1;
        for (auto cur : adj[u])
        {
            int v = cur.fi, w = cur.se;
            if (!st[v] && dist[v] > dis + w)
            {
                dist[v] = dis + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    dijikstra();
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
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