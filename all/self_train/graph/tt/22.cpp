// P1099 树网的核

// 定理 1：对于一棵所有边权均为正的树，如果其存在多条直径，
// 则各直径的中点（不一定恰好是某个节点，可能在某条边的内部）是唯一的。

// 意思是全部直径的中点唯一

// 引理 2.2：若路径存在不位于直径上的部分
// 这条路径对应的偏心距一定不会比全部位于直径上的路径的偏心距的最小值更小。

// 定理 2：设在所有满足长度限制的路径中，取得最小偏心距的路径得到的偏心距为 minBCC，
// 则对于任意一条直径，都存在一条长度不超过 s 的路径 F，使得 BCC(F)=minBCC。

// 偏心距max(p<-[i,j]dp,p(1,i),p(1,j))->max(p<-[1,k]dp,p(1,i)，p(1，j))
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
int dist[maxn], f[maxn], diam[maxn];
vector<vector<pii>> g(maxn);
int seq[maxn], fir[maxn], pre[maxn], c[maxn];
void dfs(int u, int fa)
{
    f[u] = fa;
    for (auto [v, w] : g[u])
    {
        if (v == fa)
            continue;
        dist[v] = dist[u] + w;
        c[v] = w;
        dfs(v, u);
    }
}
int dfs1(int u, int fa)
{
    int res = 0;
    for (auto [v, w] : g[u])
    {
        if (v == fa || diam[v])
            continue;
        int t = dfs1(v, u);
        res = max(res, t + w);
    }
    return res;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dfs(1,-1);
    int s = -1, t = -1;
    for (int i = 1; i <= n; i++)
    {
        if (s == -1 || dist[i] > dist[s])
            s = i;
    }
    dist[s] = 0;
    dfs(s, -1);
    for (int i = 1; i <= n; i++)
    {
        if (t == -1 || dist[i] > dist[t])
            t = i;
    }
    int cnt = 0, w = 0;
    for (int i = t; i != -1; i = f[i])
    {
        diam[i] = 1;
        pre[++cnt] = w;
        w += c[i];
    }
    int mx = 0;
    for (int i = t; i != -1; i = f[i])
    {
        int t = dfs1(i, i);
        mx = max(t, mx);
    }
    int ans = inf;
    for (int l = 1, r = 0; r<=cnt;)
    {
        r++;
        while (pre[r] - pre[l] > k)
            l++;
        if (r<l) {
            ans=min(ans,max(pre[cnt],mx));
            continue;
        }
        ans = min(ans, max({mx, pre[l], pre[cnt] - pre[r]}));
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