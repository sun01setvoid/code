//P2396 yyy Loves Math VII
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
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
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp[1 << 24];
ll w[1 << 24];
int a[25];
int fei[2];
int lowbit(int x)
{
    return x & -x;
}
void solve()
{
    int n;
    cin >> n;
    int st = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i], w[st] = a[i], st *= 2;
    int cnt;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++)
        cin >> fei[i - 1];
    dp[0] = 1;
    for (int s = 1; s < 1 << n; s++)
    {
        bool f = 0;
        w[s] = w[s - lowbit(s)] + w[lowbit(s)];
        for (int i = 0; i < cnt; i++)
            if (w[s] == fei[i])
            {
                f = 1;
                break;
            }
        if (f)
            continue;
        int now = s;
        while (now)
        {
            int cur = lowbit(now);
            int pre = s ^ cur;
            dp[s] = ((ll)dp[s] + (ll)dp[pre]) % mod;
            now -= cur;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
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