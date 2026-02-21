//P6560 [SBCOI2020] 时光的流逝
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
vector<vii> radj(maxn), adj(maxn);
int dg[maxn], f[maxn], ans[maxn];
// 类似拓扑的话bfs层状搜索
//有平局态的博弈
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
        dg[u]++;
    }
    for (int i = 1; i <= q; i++)
    {
        int st, en;
        cin >> st >> en;
        queue<int> pq;
        for (int i = 1; i <= n; i++)
        {
            ans[i] = f[i] = 0;
            if (dg[i] == 0)
                ans[i] = -1, pq.push(i);
        }
        ans[en] = -1;
        pq.push(en);
        while (pq.size())
        {
            int t = pq.front();
            pq.pop();
            if (ans[t] == -1)
            {
                for (auto v : radj[t])
                {
                    if (ans[v] == 0)
                    {
                        ans[v] = 1;
                        pq.push(v);
                    }
                }
            }
            else if (ans[t] == 1)
            {
                for (auto v : radj[t])
                {
                    if (ans[v] == 0)
                    {
                        f[v]++;
                        if (f[v] == adj[v].size())
                        {
                            ans[v] = -1;
                            pq.push(v);
                        }
                    }
                }
            }
        }
        cout << ans[st] << endl;
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