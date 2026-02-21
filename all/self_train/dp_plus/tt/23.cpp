//windy数 SCOI2009
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>#include <bits/stdc++.h>
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
int dp[20][10][2][2];
int num[20];
int dfs(int pos, int last, int lim, int lead)
{
    // cout << pos << " " << last << " " << lim << " " << lead << endl;
    if (!lead && pos == 0)
        return 1;
    if (lead && pos == 0)
        return 0;
    if (dp[pos][last][lim][lead] != -1)
        return dp[pos][last][lim][lead];
    int val = lim ? num[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= val; i++)
    {
        if (abs(i - last) < 2)
            continue;
        if (i == 0 && lead)
            ans += dfs(pos - 1, -2, lim && (i == val), 1);
        else
        {
            ans += dfs(pos - 1, i, lim && (i == val), 0);
        }
    }
    return dp[pos][last][lim][lead] = ans;
}
int op(int b)
{
    memset(dp, -1, sizeof dp);
    int len = 0;
    while (b)
    {
        len++;
        num[len] = b % 10;
        b /= 10;
    }
    return dfs(len, -2, 1, 1);
}
void solve()
{
    int a, b;
    cin >> a >> b;
    cout << op(b) - op(a - 1) << endl;
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