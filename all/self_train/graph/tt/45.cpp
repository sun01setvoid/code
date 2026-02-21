//1038 神了，题意不清
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int d[maxn],out[maxn];
int ans[maxn], sta[maxn];
vector<vector<pii>> g(maxn);
void solve()
{
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> ans[i] >> u;
        if (!ans[i])ans[i] -= u;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        d[v]++;
        out[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        auto cur = q.front();
        q.pop();
        for (auto [v, w] : g[cur])
        {
            d[v]--;
            if (ans[cur] > 0)
                ans[v] += w * ans[cur];
            if (d[v] == 0)
            {
                q.push(v);
            }
        }
    }
    bool f = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!out[i] && ans[i] > 0)
        {
            f = 1;
            cout << i << " " << ans[i] << endl;
        }
    }
    if (!f)
        cout << "NULL" << endl;
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