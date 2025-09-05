#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ls p << 1
#define rs p << 1 | 1
#define fi first
#define se second
#define pa pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
/*
        _/_/_/     _/_/_/_/_/_/_/
      _/                 _/
     _/                  _/
     _/                  _/
     _/                  _/
      _/                 _/
        _/_/_/           _/
*/
// 再不卷就退役了
const int z = 2e5 + 10;
const int zz = 2e5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
struct node
{
    int val, id;
    bool operator<(const node &t) const
    {
        return val < t.val;
    }
} w[30];
int pr[30], n, m, to[30];
vii G[30];
int dp[1 << 24]; // 从这个状态到结束的最小值
int dfs(int now, int cnt)
{
    if (now == (1ll << n) - 1)
    {
        return dp[now] = 0;
    }
    if (dp[now])
        return dp[now];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pr[i] == 0 && ((now >> (i - 1)) & 1) == 0)
            sum += (1ll << (i - 1));
    }
    for (int i = 1; i <= n; i++)
    {
        if ((sum >> (i - 1)) & 1)
        {
            for (auto v : G[i])
                pr[v]--;
        }
    }
    int mi = inf;
    for (int i = n; i >= 1; i--)
    {
        if ((sum >> (i - 1)) & 1)
        {
            mi = min(mi, dfs(now + sum, cnt )+ w[i].val);
            sum -= 1ll << (i - 1);
            for (auto v : G[i])
                pr[v]++;
        }
    }
    return dp[now] = mi;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i].val, w[i].id = i;
    sort(w + 1, w + 1 + n);
    for (int i = 1; i <= n; i++)
        to[w[i].id] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u = to[u];
        v = to[v];
        G[u].pb(v);
        pr[v]++;
    }
    int ans = dfs(0, 0);
    cout << ans << endl;
}
signed main()
{
    IOS;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}