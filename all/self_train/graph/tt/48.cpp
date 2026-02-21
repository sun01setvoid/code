// 5960 差分约束
// 超级源点设置界限，跑最短路就是跑到每个的上界，跑最长路就是跑到每个的上界
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 1e9;
const int maxn = 110;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dist[maxn];
bool vis[maxn];
int to[maxn];
vector<vector<pii>> g(maxn);
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n + 1; i++)
        dist[i] = inf, g[i].clear(), to[i] = vis[i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v + 1, w});
        g[v + 1].pb({u, -w});
    }
    queue<int> q;
    dist[0] = 0;
    vis[0] = 1;
    q.push(0);
    for (int i = 1; i <= n; i++)
    {
        g[0].pb({i, 0});
    }
    bool f = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        if (to[u] >= n + 2)
        {
            f = 0;
            break;
        }
        for (auto &[v, w] : g[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                to[v] = to[u] + 1;
                if (!vis[v])
                    q.push(v), vis[v] = 1;
            }
        }
    }
    if (!f)
        cout << "false" << endl;
    else
    {
        cout << "true" << endl;
    }
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