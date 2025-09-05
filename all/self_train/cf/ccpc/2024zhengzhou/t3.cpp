#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int a, b;
int ans, bs;
unordered_map<int, int> vis;
vector<array<int, 4>> path;
vector<array<int, 4>> res;
void dfs(int x, int y, int step)
{
    if (x > a || y > b || x < 0 || y < 0)
        return;
    if (step >= ans)
        return;
    if (x == a && y == 0 || x == a && y == b || x == 0 && y == 0 || x == 0 && y == b)
    {
        if (step < ans)
        {
            ans = step;
            res = path;
        }
    }
    if (vis.count(x * bs + y))
        return;
    vis[x * bs + y] = 1;
    path.pb({0, 0, 2 * x, 2 * y});
    dfs(2 * x, 2 * y, step + 1);
    path.pop_back();
    path.pb({a, 0, 2 * x - a, 2 * y});
    dfs(2 * x - a, 2 * y, step + 1);
    path.pop_back();
    path.pb({0, b, 2 * x, 2 * y - b});
    dfs(2 * x, 2 * y - b, step + 1);
    path.pop_back();
    path.pb({a, b, 2 * x - a, 2 * y - b});
    dfs(2 * x - a, 2 * y - b, step + 1);
    path.pop_back();
}
void solve()
{
    int x, y;
    cin >> a >> b >> x >> y;
    bs = max(a, b);
    ans = max(a != 0 ? log2(2 * a - 1) + 1 : 1, b != 0 ? log2(2 * b - 1) + 1 : 1);
    dfs(x, y, 0);
    if (ans != 0 && res.size() == 0)
    {
        cout << -1;
        return;
    }
    cout << ans << endl;
    for (int i = ans - 1; i >= 0; i--)
    {
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << res[i][3] << endl;
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