// P1539 01矩阵
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
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
const int mod = 10007;
const double eps = 1e-7;
//-----------------------------------------------------//
//或者轮廓线dp也可以
int dp[2][1 << 16];
vector<int> st;
vector<int> wt;
vector<string> str(250);
int n, m;
int val;
void dfs(int id, int s, int t)
{
    if (id == 0)
    {
        if (t == m)
        {
            st.push_back(val);
            return;
        }
        if (str[s][t] == '.')
        {
            val = val * 2;
            dfs(id, s, t + 1);
            val /= 2;
            if (val % 2 == 0)
                val = val * 2 + 1, dfs(id, s, t + 1), val /= 2;
        }
        else if (str[s][t] == '0')
        {
            val = val * 2;
            dfs(id, s, t + 1);
            val /= 2;
        }
        else
        {
            if (val % 2 == 1)
                return;
            val = val * 2 + 1;
            dfs(id, s, t + 1);
            val /= 2;
        }
    }
    else if (id == 1)
    {
        if (t == n)
        {
            st.push_back(val);
            return;
        }
        if (str[t][s] == '.')
        {
            val = val * 2;
            dfs(id, s, t + 1);
            val /= 2;
            if (val % 2 == 0)
                val = val * 2 + 1, dfs(id, s, t + 1), val /= 2;
        }
        else if (str[t][s] == '0')
        {
            val = val * 2;
            dfs(id, s, t + 1);
            val /= 2;
        }
        else
        {
            if (val % 2 == 1)
                return;
            val = val * 2 + 1;
            dfs(id, s, t + 1);
            val /= 2;
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string strt;
        cin >> strt;
        str[i] = strt;
    }
    dp[0][0] = 1;
    int cur = 1;
    if (n > m)
    {
        for (int i = 0; i < (1 << m); i++)
        {
            if (i & i >> 1)
                continue;
            else
                wt.pb(i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (1 << m); j++)
                dp[cur][j] = 0;
            st.clear();
            val = 0;
            dfs(0, i, 0);
            for (auto j : st)
            {
                for (auto k : wt)
                {
                    if (j & k)
                        continue;
                    dp[cur][j] = (dp[cur][j] + dp[cur ^ 1][k]) % mod;
                }
            }
            cur ^= 1;
        }
        cur ^= 1;
        int ans = 0;
        for (int i = 0; i < (1 << m); i++)
            ans = (ans + dp[cur][i]) % mod;
        cout << ans << endl;
    }
    else
    {
        for (int i = 0; i < (1 << n); i++)
        {
            if (i & i >> 1)
                continue;
            else
                wt.pb(i);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < (1 << n); j++)
            {
                dp[cur][j] = 0;
            }
            st.clear();
            val = 0;
            dfs(1, i, 0);
            for (auto j : st)
            {
                for (auto k : wt)
                {
                    if (j & k)
                        continue;
                    dp[cur][j] = (dp[cur][j] + dp[cur ^ 1][k]) % mod;
                }
            }
            cur ^= 1;
        }
        cur ^= 1;
        int ans = 0;
        for (int i = 0; i < (1 << m); i++)
            ans = (ans + dp[cur][i]) % mod;
        cout << ans << endl;
    }
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