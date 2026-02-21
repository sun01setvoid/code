
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dist[maxn][15];
int st[maxn][15];
int n, m, k;
int s, t;
vector<vector<pii>> g(maxn);
void dij()
{
    dist[s][0] = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
    q.push({0, {s, 0}});
    while (q.size())
    {
        auto [dis, cur] = q.top();
        q.pop();
        auto [u, id] = cur;
        if (st[u][id])
            continue;
        st[u][id] = 1;
        for (auto ne : g[u])
        {
            auto [v, c] = ne;
            if (!st[v][id] && dist[v][id] > dis + c)
            {
                dist[v][id] = dis + c;
                q.push({dist[v][id], {v, id}});
            }
            if (id + 1 <= k && !st[v][id + 1] && dist[v][id + 1] > dis)
            {
                dist[v][id + 1] = dis;
                q.push({dist[v][id + 1], {v, id + 1}});
            }
        }
    }
}
void solve()
{
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m >> k;
    cin >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    dij();
    int ans = inf;
    for (int i = 0; i <= k; i++)
        ans = min(dist[t][i], ans);
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