#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, m, d;
bool vis[maxn][2]; // 以机器人
bool st[maxn][2];  // 从1开始
int dist[maxn][2]; // 0偶，1奇
int dis[maxn][2];  // 从1开始
pii pre[maxn][2];
vector<vii> adj(maxn);
void solve()
{
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
    {
        vis[i][0] = vis[i][1] = 0;
        st[i][0] = st[i][1] = 0;
        dist[i][0] = dist[i][1] = inf;
        dis[i][0] = dis[i][1] = inf;
        adj[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int k;
    queue<pii> q;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int pos;
        cin >> pos;
        q.push({pos, 0});
        dist[pos][0] = 0;
        vis[pos][0] = 1;
    }
    while (q.size())
    {
        auto cur = q.front();
        int u = cur.fi, p = cur.se;
        q.pop();
        if (dist[u][p] + 1 > d)
            break;
        for (auto v : adj[u])
        {
            if (!vis[v][p ^ 1])
            {
                dist[v][p ^ 1] = dist[u][p] + 1;
                vis[v][p ^ 1] = 1;
                q.push({v, p ^ 1});
            }
        }
    }
    while (q.size())
        q.pop();
    q.push({1, 0});
    dis[1][0] = 0;
    st[1][0] = 1;
    int en = -1, f = -1;
    while (q.size())
    {
        auto cur = q.front();
        int u = cur.fi, p = cur.se;
        q.pop();
        if (u == n)
        {
            en = n, f = p;
            break;
        }
        for (auto v : adj[u])
        {
            if (!st[v][p ^ 1] && (!vis[v][p ^ 1] || dis[u][p] + 1 < dist[v][p ^ 1]))
            {
                dis[v][p ^ 1] = dis[u][p] + 1;
                st[v][p ^ 1] = 1;
                pre[v][p ^ 1] = {u, p};
                q.push({v, p ^ 1});
            }
        }
    }
    if (en == -1)
    {
        cout << -1 << endl;
        return;
    }
    vii ans;
    for (int u = en, p = f; dis[u][p] != 0;)
    {
        ans.pb(u);
        auto t = pre[u][p];
        u = t.fi, p = t.se;
    }
    cout << ans.size() << endl;
    cout << 1 << " ";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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