//P4381  Island
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n;
int h[maxn], e[maxm], w[maxm], ne[maxm], idx;
int fu[maxn], fw[maxn], q[maxn];
int cir[maxn], ed[maxn], cnt;
int s[maxn], d[maxn * 2], sum[maxn * 2];
bool st[maxn], ins[maxn];
int ans;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
void dfs_c(int u, int from)
{
    st[u] = ins[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        if (i == (from ^ 1)) continue;  //不是树的话，找环还是用边比较好，因为会有多重边，走fa是错的
        int j = e[i];
        fu[j] = u, fw[j] = w[i];
        if (!st[j]) dfs_c(j, i);
        else if (ins[j])
        {
            cnt ++ ;
            ed[cnt] = ed[cnt - 1];
            int sum = w[i];
            for (int k = u; k != j; k = fu[k])
            {
                s[k] = sum;
                sum += fw[k];
                cir[ ++ ed[cnt]] = k;
            }
            s[j] = sum, cir[ ++ ed[cnt]] = j;//环的最后可以一个放全部的值，是这样的
            //实际前缀和的话每个点都是要存值的，只不过是为了方便，才让是s[0]=0,这和原来的点无关，是特殊加的
        }
    }

    ins[u] = false;
}

int dfs_d(int u)
{
    st[u] = true;
    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j]) continue;
        int dist = dfs_d(j) + w[i];
        if (dist >= d1) d2 = d1, d1 = dist;
        else if (dist > d2) d2 = dist;
    }
    ans = max(ans, d1 + d2);
    return d1;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        h[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(i, a, b);
        add(a, i, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            dfs_c(i, -1);
    }
    for (int i = 1; i <= n; i++)
        st[i] = 0;
    for (int i = 1; i <= ed[cnt]; i++)
        st[cir[i]] = 1;//环上的点特殊处理
    int res = 0;
    for (int i = 1; i <= cnt; i++)
    {
        ans = 0;
        int sz = 0;
        for (int j = ed[i - 1] + 1; j <= ed[i]; j++)
        {
            int k = cir[j];
            d[sz] = dfs_d(k);
            sum[sz] = s[k];
            sz++;
        }
        for (int j = 0; j < sz; j++)
        {
            d[sz + j] = d[j], sum[sz + j] = sum[j] + sum[sz - 1];
        }
        int hh = 0, tt = -1;
        for (int j = 0; j < sz * 2; j++)
        {
            if (hh <= tt && j - q[hh] >= sz)
                hh++;
            if (hh <= tt)
            {
                ans = max(ans, d[j] + sum[j] + d[q[hh]] - sum[q[hh]]);
            }
            while (hh <= tt && d[q[tt]] - sum[q[tt]] <= d[j] - sum[j])
                tt--;
            q[++tt] = j;
        }
        res += ans;
    }
    cout << res << endl;
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