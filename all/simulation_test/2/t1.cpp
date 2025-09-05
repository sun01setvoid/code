#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define debug(x) cerr << #x << '=' << (x) << endl
#define endl '\n'
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 510;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 9;
const ld eps = 1e-7;
//-----------------------------------------------------//
vector<vector<pii>> adj(maxn);
pii a[maxn];
int dis(int u, int v)
{
    return (a[u].fi - a[v].fi) * (a[u].fi - a[v].fi) + (a[u].se - a[v].se) * (a[u].se - a[v].se);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i].pb({max(dis(i, j), 1ll), j});
        }
        sort(adj[i].begin(), adj[i].end());
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            vector<bool> vis(n + 1, 0);
            ans = min(ans, adj[j].back().fi);
            for (int k = 0, s = adj[j].size() - 1; k < adj[i].size(); k++)
            {
                int u = adj[i][k].se, r1 = adj[i][k].fi, r2;
                vis[u] = 1;
                while (s >= 0 && vis[adj[j][s].se])
                    s--;
                if (s == -1)
                    r2 = 0;
                else
                    r2 = adj[j][s].fi;
                ans = min(ans, r1 + r2);
            }
        }
    }
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