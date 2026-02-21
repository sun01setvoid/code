//模板 最小生成树
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
int p[maxn];
int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    vector<array<int, 3>> ed;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ed.pb({w, u, v});
    }
    sort(ed.begin(), ed.end());
    int ans = 0;
    for (auto [w, u, v] : ed)
    {
        int fu = find(u), fv = find(v);
        if (fu == fv)
            continue;
        p[fu] = fv;
        ans += w;
    }
    for (int i = 2; i <= n; i++)
    {
        if (find(i) != find(i - 1))
        {
            cout << "orz" << endl;
            return;
        }
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