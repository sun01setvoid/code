// 方法二：dijkstra染色
//两两之间最短路最短，但不知道具体是那两条路之间
//两两全源的话，我们要借助中间边来操作
//染色可以避免取到相同的顶点
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define pii pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;

vector<pii> edge[2][maxn];

int n, m, k;
int a[maxn];
int dis[2][maxn], col[2][maxn];

void dij(int fg)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<bool> vis(maxn, 0);
    for (int i = 1; i <= n; i++)
    {
        dis[fg][i] = inf;
        col[fg][i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        dis[fg][a[i]] = 0;
        col[fg][a[i]] = a[i];
        q.push({0, a[i]});
    }
    while (q.size())
    {
        auto [diss, u] = q.top();
        q.pop();
        if (vis[u])
            continue;
        for (auto &[v, w] : edge[fg][u])
        {
            if (dis[fg][v] > dis[fg][u] + w)
            {
                dis[fg][v] = dis[fg][u] + w;
                col[fg][v] = col[fg][u];//最近的点
                q.push(pii(dis[fg][v], v));
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edge[0][x].push_back({y, w});
        edge[1][y].push_back({x, w});
    }
    for (int i = 0; i < k; i++)
        cin >> a[i];
    dij(0), dij(1);
    int ans = inf;
    for (int u = 1; u <= n; u++)
    {
        for (auto &[v, w] : edge[0][u])
        {
            if (col[0][u] == col[1][v])
                continue;
            ans = min(ans, dis[0][u] + dis[1][v] + w);
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        edge[0][i].clear();
        edge[1][i].clear();
    }
}
signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}