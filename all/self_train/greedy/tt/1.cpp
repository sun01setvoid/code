// P1007 独木桥
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
int l, n;
int a[maxn];
void solve()
{
    cin >> l >> n;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans1 = max(ans1, min(a[i], l + 1 - a[i]));
        ans2 = max(ans2, max(a[i], l + 1 - a[i]));//类似于灵魂互换，走的时间总共是不变的，时间交换了，时间的种类也不变
    }
    cout << ans1 << " " << ans2 << endl;
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