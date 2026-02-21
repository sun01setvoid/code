// P1522 牛的旅行
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
const double inf = 1e36;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-10;
//-----------------------------------------------------//
double dp[200][200];
int p[200];
pii a[200];
double ma[200];
double fm[200];
int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        p[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = inf;
        dp[i][i] = 0;
    }
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '0')
                continue;
            dp[i][j + 1] = sqrt((a[j + 1].fi - a[i].fi) * (a[j + 1].fi - a[i].fi) + (a[j + 1].se - a[i].se) * (a[j + 1].se - a[i].se));
            int f1 = find(i), f2 = find(j + 1);
            if (f1 != f2)
            {
                p[f1] = f2;
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (abs(dp[i][k] - inf) <= eps || abs(dp[k][j] - inf) <= eps)
                    continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    vector<vii> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int fa = find(i);
        adj[fa].pb(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 0)
            continue;
        double ma_id = 0;
        for (auto x : adj[i])
        {
            double ans = 0;
            for (auto y : adj[i])
            {
                ans = max(ans, dp[x][y]);
            }
            ma[x] = ans;
            ma_id = max(ans, ma_id);
        }
        fm[i] = ma_id;
    }
    double ans = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[i] == p[j])
                continue;
            double dis = sqrt((a[j].fi - a[i].fi) * (a[j].fi - a[i].fi) + (a[j].se - a[i].se) * (a[j].se - a[i].se));
            ans = min(ans, max({ma[i] + dis + ma[j], fm[p[i]], fm[p[j]]}));
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
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