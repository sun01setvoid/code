#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define IOS ios::sync_with_stdio(0);
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
int n, m, tot;
vii mp[maxn], g[maxn];
int dfn[maxn], low[maxn], st[maxn], cut[maxn];
set<int> bel[maxn];
int bcc, top, d[maxn], x[maxn], y[maxn];
vii ans[maxn], ed[maxn];
int dis[maxn];
// 全部的点双连通中点的个数最多大概2*n,观察那个缩点的树
// 观察那个缩点后的树，你能体会出连边的方式
// 但是点双真的能缩点吗？
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++tot;
    st[++top] = u;
    int child = 0;
    for (auto v : mp[u])
    {
        if (!dfn[v])
        {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                bcc++;
                while (st[top + 1] != v)
                {
                    int y = st[top];
                    bel[y].insert(bcc);
                    ans[bcc].pb(st[top--]);
                }
                ans[bcc].pb(u);
                bel[u].insert(bcc);
            }
        }
        else if (v != fa)
            low[u] = min(low[u], dfn[v]);
    }
    if (fa == 0 && child == 0) // 孤立点特判
        ans[++bcc].pb(u), bel[u].insert(bcc);
}
void init()
{
    for (int i = 1; i <= 2*n; i++)
    {
        mp[i].clear(), g[i].clear();
        bel[i].clear();
        dfn[i] = low[i] = 0;
        cut[i] = 0;
        d[i] = 0;
        st[i]=0;
        ans[i].clear(), ed[i].clear();
    }
    tot = bcc = top = 0;
}
void solve()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i];
        mp[x[i]].pb(y[i]);
        mp[y[i]].pb(x[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i])
            continue;
        top = 0;
        tarjan(i, 0);
    }
    for (int i = 1; i <= m; i++)
    {
        int u = x[i], v = y[i];
        if ((int)bel[u].size() > (int)bel[v].size())
            swap(u, v); // 小的一般是1和2
        for (auto id : bel[u])
        {
            if (bel[v].count(id))
            {
                ed[id].pb(i);
                break;
            }
        }
    }
    bool f = 1;
    int len = -1;
    for (int k = 1; k <= bcc && f; ++k)
    {
        for (auto id : ed[k])
        {
            ++d[x[id]], ++d[y[id]];
            g[x[id]].pb(y[id]);
            g[y[id]].pb(x[id]);
        }
        int cnt[4] = {0, 0, 0, 0};
        for (auto x : ans[k])
        {
            if (d[x] <= 2)
                ++cnt[d[x]];
            else
                ++cnt[3];
        }
        if (cnt[0] == 1 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0)
        {
        }
        else if (cnt[0] == 0 && cnt[1] == 2 && cnt[2] == 0 && cnt[3] == 0)
        {
        }
        else if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == (int)ans[k].size() && cnt[3] == 0)
        {
            if (len == -1)
                len = ans[k].size();
            else if (len != ans[k].size())
                f = 0;
        }
        else if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == ans[k].size() - 2 && cnt[3] == 2)
        {
            vii key;
            for (auto x : ans[k])
                if (d[x] > 2)
                    key.pb(x);
            queue<int> q;
            for (auto x : ans[k])
                dis[x] = inf;
            dis[key[0]] = 0;
            q.push(key[0]);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto v : g[u])
                {
                    if (dis[v] == inf)
                        dis[v] = dis[u] + 1, q.push(v);
                    else if (v == key[1] && dis[v] != dis[u] + 1)
                        f = 0;
                }
            }
            if (len == -1)
                len = 2 * dis[key[1]];
            else if (len != 2 * dis[key[1]])
                f = 0;
        }
        else
            f = 0;
        for (auto id : ed[k])
            --d[x[id]], --d[y[id]];
        for (auto v : ans[k])
            g[v].clear();
    }
    cout << (f ? "Yes" : "No") << endl;
}
signed main()
{
    IOS;
    int _;
    cin >> _;
    while (_--)
        solve();
}