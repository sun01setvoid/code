#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}
int count2(int l, int r)
{
    vector<int> pri = {2, 3, 5, 7};
    int n = pri.size();
    int res = 0;
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        int lcmval = 1;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                lcmval = lcm(lcmval, pri[i]);
                if (lcmval > r)
                    break;
            }
        }
        if (lcmval > r)
            continue;
        int cnt = r / lcmval - (l - 1) / lcmval;
        if (__builtin_popcount(mask) % 2 == 1)
            res += cnt;
        else
            res -= cnt;
    }
    return res;
}
int count1(int l, int r)
{
    return (r - l + 1) - count2(l, r);
}
void solve()
{
    int l, r;
    cin >> l >> r;
    cout << count1(l, r) << '\n';
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