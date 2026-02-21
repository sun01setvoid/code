// P1003 铺地毯
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
vector<array<int, 4>> ans;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, g, k;
        cin >> a >> b >> g >> k;
        ans.pb({a, b, g, k});
    }
    int x, y;
    cin >> x >> y;
    int res = -1;
    int cnt=1;
    for (auto [a, b, g, k] : ans)
    {
        int p1 = a, p2 = b, p3 = a + g, p4 = b + k;
        if (p1 <= x && x <= p3 && p2 <= y && y <= p4)
            res = cnt;
            ++cnt;
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