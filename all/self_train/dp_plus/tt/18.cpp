// CF791D
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
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
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//

void solve()
{
    //只要r大于前面的l的最大值
    //先考虑前面合法，这么维护
    int n;
    int ans = 1;
    cin >> n;
    deque<pii> q;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        while (!q.empty() && q.front().fi > r)
        {
            q.pop_front();
        }
        if (!q.empty())
        {
            ans = max(ans, i - q.front().se + 1);
        }
        int tmp = i;
        while (!q.empty() && q.back().fi < l)
        {
            tmp = q.back().se;
            q.pop_back();
        }
        q.push_back({l, tmp});
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