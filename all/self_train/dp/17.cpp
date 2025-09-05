// P5322 排兵布阵
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
void solve()
{
    int s, n, m;
    cin >> s >> n >> m;
    vector<vii> tmp(n + 1, vii(s + 1));
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tmp[j][i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(tmp[i].begin() + 1, tmp[i].end());
        for (int j = 1; j <= s; j++)
        {
            tmp[i][j] = 2 * tmp[i][j] + 1;
        }
    }
    vii dp(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= s; k++)
            {
                if (j >= tmp[i][k])
                    dp[j] = max(dp[j], dp[j - tmp[i][k]] + k * i);
                else break;
            }
        }
    }
    cout << dp[m] << endl;
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