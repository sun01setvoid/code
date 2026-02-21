#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int maxn = 200;
const int maxm = 1e6 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
double dist[maxn][550];
pii pre[maxn][550];
int st[maxn][550];
vector<array<int, 3>> g[maxn];
int n, m, d;
void dij()
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= 500; j++)
            dist[i][j] = inf;
    }
    dist[0][70] = 0.0;
    priority_queue<pair<double, pii>, vector<pair<double, pii>>, greater<pair<double, pii>>> q;
    q.push(pair<double, pii>(0.0, {0, 70}));
    while (q.size())
    {
        auto [dis, cur] = q.top();
        auto [u, id] = cur;
        q.pop();
        if (st[u][id])
            continue;
        st[u][id] = 1;
        for (auto cur : g[u])
        {
            auto [ne, v, l] = cur;
            if (v == 0)
                v = id;
            if (st[ne][v])
                continue;
            if (dist[ne][v] > dis + (double)l / v)
            {
                dist[ne][v] = dis + (double)l / v;
                pre[ne][v] = {u, id};
                q.push(pair<double, pii>(dist[ne][v], {ne, v}));
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> d;
    for (int i = 0; i <= m - 1; i++)
    {
        int a, b, v, l;
        cin >> a >> b >> v >> l;
        g[a].pb({b, v, l});
    }
    dij();
    double ans = inf;
    pii tmp;
    for (int i = 1; i <= 500; i++)
    {
        if (dist[d][i] < ans)
        {
            ans = dist[d][i], tmp = {d, i};
        }
    }
    pii a = {0, 70};
    vector<pii> path;
    while (tmp != a)
    {
        path.pb(tmp);
        // debug(tmp.fi);
        // debug(tmp.se);
        tmp = pre[tmp.fi][tmp.se];
    }
    cout << 0 << " ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i].fi << " ";
    }
}
signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}