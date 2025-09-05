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
const int N = 1200010, M = N * 2;

int n;
int h[N], e[M], w[M], ne[M], idx;
int fu[N], fw[N], q[N];
int cir[N], ed[N], cnt;
int s[N], d[N * 2], sum[N * 2];
bool st[N], ins[N];
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
        if (i == (from ^ 1)) continue;
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
            s[j] = sum, cir[ ++ ed[cnt]] = j;
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
        int ans = 0;
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