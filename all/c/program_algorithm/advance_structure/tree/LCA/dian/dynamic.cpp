// 前缀直径集，动态插入直径
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define IOS ios::sync_with_stdio(0);cin.tie(0)
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e6 + 5;
int n, q, lv[maxn], rv[maxn];
pii w[maxn];
vector<pii> ed[maxn];
namespace LCA_Solver
{
    int dep[maxn], dis[maxn], seq[maxn], fir[maxn], f[maxn][20], _log[maxn], idx;
    inline void DFS(int now = 1, int fa = 0)
    {
        seq[++idx] = now;
        fir[now] = idx;
        dep[now] = dep[fa] + 1;
        for (auto [to, w] : ed[now])
            if (to != fa)
                dis[to] = dis[now] + w, DFS(to, now), seq[++idx] = now;
    }
    inline int mindep(int x, int y)
    {
        return dep[x] < dep[y] ? x : y;
    }
    inline void init(void)
    {
        int i, j;
        for (_log[0] = -1, i = 1; i <= idx; ++i)
            _log[i] = _log[i >> 1] + 1;
        for (i = 1; i <= idx; ++i)
            f[i][0] = seq[i];
        for (j = 1; j < 20; ++j)
            for (i = 1; i + (1 << j) - 1 <= idx; ++i)
                f[i][j] = mindep(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
    }
    inline int LCA(int x, int y)
    {
        x = fir[x];
        y = fir[y];
        if (x > y)
            swap(x, y);
        int k = _log[y - x + 1];
        return mindep(f[x][k], f[y - (1 << k) + 1][k]);
    }
    inline int getdis(int x, int y)
    {
        if (x == 0 || y == 0)
            return 0;
        return dis[x] + dis[y] - 2LL * dis[LCA(x, y)];
    }
}; 
using namespace LCA_Solver;
signed main()
{
    IOS;
    cin >> n >> q;
    for (int i = 0; i <= n - 1; i++)
        cin >> w[i].fi, w[i].se = i + 1;
    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        ed[x].pb({y, z});
        ed[y].pb({x, z});
    }
    DFS();
    init();
    sort(w, w + n);
    int mex = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (w[i].fi == mex)
            mex++;
        else
            break;
    }
    lv[0] = w[0].se, rv[0] = w[0].se;
    for (int i = 1; i <= mex - 1; i++)
    {
        int d1 = getdis(lv[i - 1], w[i].se), d2 = getdis(rv[i - 1], w[i].se);
        int d0 = getdis(lv[i - 1], rv[i - 1]);
        if (d0 >= d1 && d0 >= d2)
            lv[i] = lv[i - 1], rv[i] = rv[i - 1];
        else if (d1 >= d0 && d1 >= d2)
            rv[i] = w[i].se, lv[i] = lv[i - 1];
        else
            lv[i] = w[i].se, rv[i] = rv[i - 1];
    }
    for (int i = 1; i <= q; i++)
    {
        int x, k;
        cin >> x >> k;
        int l = 0, r = mex - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (max(getdis(lv[mid], x), getdis(rv[mid], x)) <= k)
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << r + 1 << endl;
    }
}
