// P4170  涂色
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
// 带贪区间dp
//区间也要考虑拓扑序
//考虑两端相同，那么去掉任意一端就可以了
//因为仍然要考虑内部怎么染色，是否有相同色块，所以留一端
int dp[110][110];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    rep(i,1,n)rep(j,1,n) dp[i][j]=INF;
    rep(i, 1, n) dp[i][i] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (s[i - 1] == s[j - 1])
                dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            else
            {
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][k] + dp[k + 1][j], dp[i][j]);
                }
            }
        }
    }
    cout << dp[1][n] << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}