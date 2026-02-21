// P4158 粉刷匠
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
const int maxn = 60;
const int maxm = 2510;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int dp1[maxn][maxn][maxn], dp2[maxn][maxm], mx[maxn][maxn][maxn];
//-----------------------------------------------------//
void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    string s;
    rep(i, 1, n)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            int cnt0 = 0, cnt1 = 0;
            for (int k = j; k < s.size(); k++)
            {
                if (s[k] == '0')
                    cnt0++;
                else
                    cnt1++;
                mx[i][j][k] = max(cnt0, cnt1);
            }
        }
        for (int j = 0; j < s.size(); j++)
        {
            dp1[i][j][1] = max(dp1[i][j][1], mx[i][0][j]); // 因为要尽量大，所以后面全部都涂色
            for (int k = 2; k <= j + 1; k++)
            {
                for (int l = k - 2; l < j; l++)
                {
                    dp1[i][j][k] = max(dp1[i][j][k], dp1[i][l][k - 1] + mx[i][l + 1][j]);
                }
            }
        }
    }
    rep(i, 1, n)
    {
        rep(j, 1, t)
        {
            dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);
            rep(k, 1, min(j, m))
            {
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - k] + dp1[i][m - 1][k]);
            }
        }
    }
    cout << dp2[n][t] << endl;
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