// P2731
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
vector<vector<pii>> g(maxn);
bool used[2 * maxn];
int del[maxn], d[maxn];
stack<int> stk;
void dfs(int u)
{
    for (int i = del[u]; i < g[u].size(); i = del[u])
    {
        del[u] = i + 1;
        if (used[g[u][i].se / 2])
            continue;
        int v = g[u][i].fi;
        used[g[u][i].se / 2] = 1;
        dfs(v);
    }
    stk.push(u);
}
void solve()
{
    int m;
    cin >> m;
    int st = 501;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        d[a]++, d[b]++;
        st = min(st, min(a, b));
        g[a].pb({b, 2 * i});
        g[b].pb({a, 2 * i + 1});
    }
    int ct = 0;
    for (int i = 500; i >= 1; i--)
    {
        if (d[i] & 1)
        {
            ct++;
            st = i;
        }
    }
    for (int i = 1; i <= 500; i++)
        sort(g[i].begin(), g[i].end());
    dfs(st);
    while (!stk.empty())
    {
        cout << stk.top() << endl;
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