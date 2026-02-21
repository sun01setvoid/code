// P4544 Buying Feed G
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
const int maxn = 1e4 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[2][maxn];
int q[maxn], q1[maxn];
void solve()
{
    int k, e, n;
    cin >> k >> e >> n;
    vector<array<int, 3>> vc(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, f, c;
        cin >> x >> f >> c;
        vc[i] = {x, f, c};
    }
    sort(vc.begin() + 1, vc.begin() + n + 1);
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    int st = 1;
    for (int i = 1; i <= n; i++)
    {
        int hh = 0, tt = -1;
        for (int j = 0; j <= k; j++)
        {
            int res = dp[st ^ 1][j] + j * j * (vc[i][0] - vc[i - 1][0]) - j * vc[i][2];
            if (hh <= tt && q[hh] < j - vc[i][1])
                hh++;
            while (hh <= tt && q1[tt] > res)
                tt--;
            q[++tt] = j;
            q1[tt] = res;
            dp[st][j] = q1[hh] + j * vc[i][2];
        }
        st ^= 1;
    }
    st ^= 1;
    int ans = dp[st][k];
    if (vc[n][0] != e)
        ans += (e - vc[n][0]) * k * k;
    cout << ans << endl;
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