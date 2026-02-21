// O(nmlogm)
// P5905 模板 全源最短路
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define pii pair<int, int>
#define pb push_back
const int inf = 1e9;
const int maxn = 3010;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, m;
struct ed
{
    int u, v, w;
};
vector<ed> edges;
vector<vector<pii>> adj(maxn);
int h[maxn];
int dist[maxn];
bool st[maxn];
bool bf()
{
    // h[i]=0,建了0号源点
    bool flag = false;
    for (int i = 1; i <= n; i++) // 如果有负环，一定会一直松弛，所以在第n轮一定有松弛操作
    {                            // 然而第i轮不一定能够对应到第i次松弛，除非使用边数限制的bellmanford
        // 或者开个数组记录边数
        flag = false;
        for (auto e : edges)
        {
            auto [u, v, w] = e;
            if (dist[u] == inf)
                continue;
            if (h[v] > h[u] + w)
            {
                h[v] = h[u] + w;
                flag = true;
            }
        }
        if (!flag)
        {
            return false;
        }
    }
    return flag;
}
void dijikstra(int s)
{
    for (int i = 1; i <= n; i++)
        dist[i] = inf, st[i] = 0;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        int dis = cur.first, u = cur.second;
        if (st[u])
            continue;
        st[u] = 1;
        for (auto ne : adj[u])
        {
            int v = ne.first, w = ne.second;
            if (!st[v] && dist[v] > dis + h[u] - h[v] + w)
            {
                dist[v] = dis + h[u] - h[v] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        edges.pb({a, b, c});
    }
    bool f = bf();
    if (f)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        dijikstra(i);
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
             if (dist[j] == inf)
             {
                 ans += j * dist[j];
                 continue;
             }
            ans += (dist[j] + h[j] - h[i]) * j;
        }
        cout << ans << endl;
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