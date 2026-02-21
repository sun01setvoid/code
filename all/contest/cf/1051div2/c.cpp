
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
vector<vii> g(maxn);
int d[maxn], ans[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear(), d[i] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x > y)
            g[u].pb(v), d[v]++;
        else
            g[v].pb(u), d[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q.push(i);
    int cnt = n;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        ans[u] = cnt--;
        for (auto v : g[u])
        {
            d[v]--;
            if (d[v] == 0)
                q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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