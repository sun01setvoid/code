//P1144 最短路计数
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 100003;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, m;
vector<vii> adj(maxn);
int cnt[maxn];
int dist[maxn];
bool st[maxn];
void dijikstra()
{
    for (int i=1;i<=n;i++) dist[i]=inf;
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    cnt[1] = 1;
    while (pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        int dis = cur.fi, u = cur.se;
        if (st[u])
            continue;
        st[u] = 1;
        for (auto v : adj[u])
        {
            if (!st[v])
            {
                if (dist[v] > dis + 1)
                {
                    dist[v] = dis + 1;
                    cnt[v] = cnt[u];
                    pq.push({dist[v], v});
                }
                else if (dist[v] == dis + 1)
                {
                    cnt[v] = (cnt[u]+cnt[v])%mod;
                }
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dijikstra();
    for (int i = 1; i <= n; i++)
    {
        cout << cnt[i]<< endl;
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