// P2167 [SDOI] Bill的挑战
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define int long long
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1000003;
const double eps = 1e-7;
//-----------------------------------------------------//
string str[20];
int dp[55][1 << 15];
int match[55][55];
void solve()
{
    memset(dp, 0, sizeof dp);
    memset(match, 0, sizeof match);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    if (k > n)
    {
        cout << 0 << endl;
        return;
    }
    int len = str[0].size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (str[k][i] == '?' || str[k][i] - 'a' == j)
                {
                    match[i][j] |= 1 << k;
                }
            }
        }
    }
    dp[0][(1 << n) - 1] = 1;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            for (int s = 0; s < 1 << n; s++)
            {
                (dp[i + 1][match[i][j] & s] += dp[i][s]) %= mod;
            }
        }
    }
    int ans = 0;
    for (int s = 0; s < 1 << n; s++)
    {
        int cnt = __builtin_popcountll(s);
        if (cnt == k)
            (ans += dp[len][s]) %= mod;
    }
    cout << ans << endl;
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