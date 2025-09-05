#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 6e1 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
};
int n, p[maxn], tr[maxn];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int val)
{
    for (int i = x; i <= n + 1; i += lowbit(i))
    {
        tr[i] = min(tr[i], val);
    }
}
int qry(int x)
{
    int ans = INF;
    for (int i = x; i >= 1; i -= lowbit(i))
    {
        ans = min(ans, tr[i]);
    }
    return ans;
}
void Raze()
{
    cin >> n;
    vii p(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> p[i], tr[i] = INF;
    tr[n + 1] = INF;
    p[0] = 0, p[n + 1] = n + 1;
    vii dp(n + 2, INF);
    dp[0] = 0;
    add(1, 0); // 整体右移一位
    for (int i = 1; i <= n + 1; i++)
    {
        dp[p[i]] = min(dp[p[i]], dp[p[i] - 1]);
        int mi = qry(p[i] - 1);
        dp[p[i]] = min(dp[p[i]], mi + p[i]);
        add(p[i] + 1, dp[p[i]] - p[i]);
    }
    cout << dp[n + 1] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        Raze();
    return 0;
}