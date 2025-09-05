// P2704 NOI2001 炮兵阵地
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
int mp[110], dp[2][1030][1030];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            mp[i] = mp[i] * 2 + (s[j] == 'P' ? 1 : 0);
        }
    }
    int st = 0;
    int ans = 0;//这里表示了所有的max,所以滚动时初始状态不清零
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s < (1 << m); s++) //实际上只有60个合法状态
        {
            if ((s | mp[i]) > mp[i])
                continue;
            if (s & s << 2 || s & s << 1 || s & s >> 1 || s & s >> 2)
                continue;
            int cnt = __builtin_popcountll(s);
            for (int l = 0; l < (1 << m); l++)
            {
                if (l & l << 2 || l & l << 1 || l & l >> 1 || l & l >> 2)
                    continue;
                if (s & l)
                    continue;
                for (int fl = 0; fl < (1 << m); fl++)
                {
                    if (fl & fl << 2 || fl & fl << 1 || fl & fl >> 1 || fl & fl >> 2)
                        continue;
                    if (s & fl || l & fl)
                        continue;
                    dp[st][s][l] = max(dp[st][s][l], dp[st ^ 1][l][fl] + cnt);
                    // cout << i << " " << s << " " << l << " " << dp[st][s][l] << endl;
                }
            }
        }
        st ^= 1;
    }
    for (int i = 0; i < 1 << m; i++)
    {
        for (int j = 0; j < (1 << m); j++)
        {
            ans = max(ans, dp[st ^ 1][i][j]);
        }
    }
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