// P462 通往奥格瑞玛的道路
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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, m, b;
int a[maxn];
int dist[maxn];
bool st[maxn];
vector<vector<pii>> adj(maxn);
void dijikstra(int x)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        int dis = cur.fi, u = cur.se;
        if (st[u])
            continue;
        st[u] = 1;
        for (auto ne : adj[u])
        {
            int v = ne.fi, w = ne.se;
            if (!st[v] && a[v] <= x && dist[v] > dis + w)
            {
                dist[v] = dis + w;
                pq.push({dist[v], v});
            }
        }
    }
}
bool check(int x)
{
    dijikstra(x);
    return dist[n] <= b;
}
void solve()
{
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    int l = a[1], r = 1e9;
    dijikstra(1e9 + 10);
    if (b < dist[n])
    {
        cout << "AFK" << endl;
        return;
    }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << l << endl;
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