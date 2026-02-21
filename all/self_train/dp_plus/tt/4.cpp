// P3092 [USACO13NOV] No Change G
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
int lowbit(int x)
{
    return x & -x;
}
int a[16];
int pre[maxn];
vector<vii> p(17);
int dp[1 << 16], re[1 << 16];
unordered_map<int, int> to;
void solve()
{
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> pre[i], pre[i] = pre[i - 1] + pre[i];
    for (int i = 0; i < 1 << k; i++)
    {
        int cnt = __builtin_popcountll(i);
        p[cnt].pb(i);
    }
    for (int i = 1; i <= k; i++)
    {
        for (auto s : p[i])
        {
            int now = s;
            while (now)
            {
                int cur = lowbit(now);
                int val = a[to[cur]];
                int last = s ^ cur;
                if (dp[last] != n)
                {
                    // 二分？找最优的
                    int t = upper_bound(pre + 1, pre + n + 1, pre[dp[last]] + val) - pre;
                    dp[s] = max(dp[s], t - 1);
                }
                else
                {
                    dp[s] = n;
                    re[s] = max(re[s], re[last] + val);
                }
                now -= cur;
            }
            //debug(s);
            //debug(dp[s]);
            //debug(re[s]);
        }
    }
    if (dp[(1 << k) - 1] != n)
    {
        cout << -1 << endl;
    }
    else
        cout << re[(1 << k) - 1] << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    int st = 1;
    for (int i = 0; i < 16; i++)
        to[st] = i, st *= 2;
    while (_--)
    {
        solve();
    }
    return 0;
}