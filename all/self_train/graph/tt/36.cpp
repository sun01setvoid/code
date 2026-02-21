//p13348
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
const int maxn = 1.5e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<vector<pii>> g(maxn);
int del[maxn];
bool vis[maxn];
stack<int> stk;
int get(int i, int j)
{
    return i * 1005 + j;
}
void dfs(int u)
{
    for (int i = del[u]; i < g[u].size(); i = del[u])
    {
        del[u] = i + 1;
        if (vis[g[u][i].se / 2])
            continue;
        vis[g[u][i].se / 2] = 1;
        dfs(g[u][i].fi);
    }
    stk.push(u);
}
void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    int ans;
    if (n & 1)
        ans = n * n;
    else
        ans = n * n - n;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            if (n % 2 == 0 && i + j == n - 1)
                continue;
            if ((i + j) & 1)
            {
                int a = get(i, j + 1), b = get(i + 1, j);
                ++cnt;
                g[a].pb({b, cnt * 2});
                g[b].pb({a, cnt * 2 + 1});
            }
            else
            {
                int a = get(i, j), b = get(i + 1, j + 1);
                ++cnt;
                g[a].pb({b, cnt * 2});
                g[b].pb({a, cnt * 2 + 1});
            }
        }
    }
    dfs(0);
    cout << ans << endl;
    stk.pop();
    while (stk.size())
    {
        int cur = stk.top();
        cout << cur / 1005 << " " << cur % 1005 << endl;
        stk.pop();
    }
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