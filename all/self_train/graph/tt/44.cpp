// P1983 车站分级
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
int d[maxn];
int ans[maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = n;
    for (int i = 1; i <= m; i++)
    {
        int len;
        cin >> len;
        ++cnt;
        int mi = inf, mx = 0;
        vector<bool> vis(n + 1);
        for (int i = 1; i <= len; i++)
        {
            int x;
            cin >> x;
            mi = min(mi, x);
            mx = max(mx, x);
            vis[x] = 1;
            g[cnt].pb(x), d[x]++;
        }
        for (int i = mi + 1; i <= mx - 1; i++)
        {
            if (!vis[i])
                g[i].pb(cnt), d[cnt]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= cnt; i++)
    {
        if (!d[i])
            q.push(i);
    }
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        int dis = 1;
        if (cur > n)
            dis = 0;
        for (auto v : g[cur])
        {
            d[v]--;
            ans[v] = max(ans[v], ans[cur] + dis);
            if (!d[v])
                q.push(v);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, ans[i]);
    }
    cout << res + 1 << endl;
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