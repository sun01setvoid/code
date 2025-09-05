// P1776 宝物筛选
/*
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n, W;
    cin >> n >> W;
    vii dp(W + 1);
    for (int i = 1; i <= n; i++)
    {
        int v, w, m;
        cin >> v >> w >> m;
        for (int j = 1; j < m; j *= 2)
        {
            for (int k = W; k >= j * w; k--)
            {
                dp[k] = max(dp[k], dp[k - j * w] + j * v);
            }
            m -= j;
        }
        for (int k = W; k >= m * w; k--)
        {
            dp[k] = max(dp[k], dp[k - m * w] + m * v);
        }
    }
    cout << dp[W] << endl;
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
*/
// 单调队列优化
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int q[maxn], q2[maxn];
void solve()
{
    int n, W;
    cin >> n >> W;
    vii dp(W + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int v, w, m;
        cin >> v >> w >> m;
        if (w == 0)
        {
            ans += v * m;
            continue;
        }
        int k = W / w;
        m = min(m, k);
        for (int d = 0; d < w; d++)
        {
            int hh = 0, tt = -1;
            k = (W - d) / w;
            for (int j = 0; j <= k; j++)
            {
                if (hh <= tt && q[hh] < j - m)
                    hh++;
                while (hh <= tt && q2[tt] < dp[d + j * w] - j * v)
                {
                    tt--;
                }
                q[++tt] = j;
                q2[tt] = dp[d + j * w] - j * v;
                dp[d + j * w] = max(dp[d + j * w], q2[hh] + j * v);
            }
        }
    }
    cout << dp[W] + ans << endl;
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