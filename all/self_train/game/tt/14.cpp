
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
vector<vii> adj(maxn);
// 树形递推，树形dp
int gd[maxn];
void dfs(int u, int fa)
{
    gd[u] = 0;
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        gd[u] ^= (gd[v] + 1);
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    //直接使用sz[v]会发现由重复情况，并不是子树大小
    dfs(1, 0);
    if (gd[1])
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}