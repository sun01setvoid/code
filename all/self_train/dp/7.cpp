// P2679  子串
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
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
#define debugarrn(a, st, en)             \
    cerr << #a << "=[";                  \
    repn(i, st, en) cerr << a[i] << ' '; \
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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e2 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int dp[maxn][maxn][2];
//-----------------------------------------------------//
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    a = "#" + a, b = "&" + b;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i,m); j >= 0; j--)
        {
            for (int k = j; k >= 0; k--)
            {
                // debug(i);// debug(j);// debug(k);
                if (b[j] != a[i])
                {
                    dp[j][k][0] = (dp[j][k][0] + dp[j][k][1]) % mod;
                    dp[j][k][1] = 0;
                    // debug(dp[j][k][0]);// debug(dp[j][k][1]);
                    continue;
                }
                dp[j][k][0] = (dp[j][k][0] + dp[j][k][1]) % mod;
                dp[j][k][1] = ((j - 1 >= k ? dp[j - 1][k][1] : 0) + (j - 1 >= 0 && k - 1 >= 0 ? dp[j - 1][k - 1][0] + dp[j - 1][k - 1][1] : 0)) % mod;
                // debug(dp[j][k][0]);
                // debug(dp[j][k][1]);
            }
        }
    }
    cout << (dp[m][k][0] + dp[m][k][1]) % mod << endl;
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