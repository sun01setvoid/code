#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10;
const int maxm = 1e2 + 50;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, x, a[maxn];
vii mp[maxn];
map<int, int> ha;
int dp1[maxn][maxm], dp2[maxn][maxm];
int len;
int change[maxm][maxm];
void init()
{
    for (int i = 1; i <= n; i++)
        mp[i].clear();
}
void dfs1(int u, int fa)
{
    if (ha.count(a[u]))
        dp1[u][ha[a[u]]] += 1;
    for (int v : mp[u])
    {
        if (v == fa)
            continue;
        dfs1(v, u);
        if (x % a[u] == 0)
        {
            for (int i = 0; i < len; i++)
            {
                dp1[u][change[i][ha[a[u]]]] += dp1[v][i];
            }
        }
    }
}
void dfs2(int u, int fa)
{
    // debug(u);
    for (int v : mp[u])
    {
        if (v == fa)
            continue;
        if (x % a[v] == 0)
        {
            vii tmp(len, 0);
            if (x % a[u] == 0)
            {
                tmp[ha[a[u]]] += 1;
                for (int i = 0; i < len; i++)
                {
                    tmp[change[i][ha[a[u]]]] += dp1[v][i];
                }
            }
            for (int i = 0; i < len; i++)
            {
                dp2[v][change[i][ha[a[v]]]] += dp2[u][i] + dp1[u][i] - tmp[i];
            }
        }
        dfs2(v, u);
    }
}
void Raze()
{
    cin >> n >> x;
    init();
    ha.clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        mp[u].pb(v);
        mp[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vii tmp;
    for (int i = 1; i* i <= x; i++)
    {
        if (x % i == 0)
        {
            tmp.pb(i);
            if (x / i != i)
                tmp.pb(x / i);
        }
    }
    sort(tmp.begin(), tmp.end());
    len = tmp.size();
    for (int i = 0; i < len; i++)
        ha[tmp[i]] = i;
    for (int i = 0; i < tmp.size(); i++)
    {
        for (int j = 0; j < tmp.size(); j++)
        {
            change[i][j] = ha[tmp[i]/__gcd(tmp[i], tmp[j])*tmp[j]];
        }
    }
    dfs1(1, 0);
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < tmp.size(); j++)
        {
            cout << dp1[i][j] << " ";
        }
        cout << endl;
    }
    */
    dfs2(1, 0);
        /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < tmp.size(); j++)
        {
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }
    */
    int ans = 0;
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
        ans += dp1[i][len - 1], ans2 += dp2[i][len - 1];
    //cout << ans << endl;
    cout << ans + ans2 / 2 << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < len; j++)
            dp1[i][j] = 0, dp2[i][j] = 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        Raze();
    return 0;
}
