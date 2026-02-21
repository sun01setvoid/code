//最大生成树
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
vector<array<int, 3>> ed;
int p[maxn];
int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ed.pb({w, u, v});
    }
    sort(ed.begin(), ed.end());
    reverse(ed.begin(), ed.end());
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (cnt == k)
            break;
        auto [w, u, v] = ed[i];
        int fu = find(u), fv = find(v);
        if (fu != fv)
            p[fu] = fv, ++cnt, ans += w;
        else
            continue;
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