// P3694 邦邦的大合唱站队
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
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[1 << 20]; // 与定的摆放位置进行比较
int num[20];
int sum[maxn][20];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int s = 0; s < 1 << m; s++)
        dp[s] = inf;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x, x--, num[x]++;
        for (int j = 0; j < m; j++)
        {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][x]++;
    }
    dp[0] = 0;
    for (int s = 1; s < 1 << m; s++)
    {
        int len = 0;
        for (int j = 0; j < m; j++)
        {
            if (s >> j & 1)
                len += num[j];
        }
        for (int j = 0; j < m; j++)
        {
            if (s >> j & 1)
            {
                dp[s] = min(dp[s], dp[s ^ 1 << j] + num[j] - (sum[len][j] - sum[len - num[j]][j]));
            }
        }
    }
    cout << dp[(1 << m) - 1] << endl;
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