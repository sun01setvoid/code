
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
const int inf = 1e16;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n, a[maxn];
void solve()
{
    cin >> n;
    map<int, vii, greater<int>> mp;
    int mi = 1e16;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mi = min(a[i], mi);
    }
    for (int i = 1; i <= n; i++)
    {
        mp[a[i]].pb(1);
        for (int j = 2;; j++)
        {
            int f = powl(a[i], 1.0L / j);
            if (f == 1)
                break;
            mp[f].pb(j);
        }
    }
    int res = 0;
    for (auto [val, vc] : mp)
    {
        for (int sg : vc)
        {
            res ^= (sg - 1);
            res ^= sg;
        }
        if (val <= mi && res == 0)
        {
            cout << "Bob" << endl;
            return;
        }
    }
    cout << "Alice" << endl;
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