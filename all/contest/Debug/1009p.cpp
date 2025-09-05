#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
#define mid ((l + r) >> 1)
#define lowbit(i) ((i) & (-i))
const int mod1 = 1e9 + 7, mod2 = 998244353;
int a[3010][3010];
int f1[3010][3010], f2[3010][3010];
int g1[3010][3010], g2[3010][3010];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    // cout<<k<<"!!"<<endl;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            f1[i][j] = f2[i][j] = g1[i][j] = g2[i][j] = a[i][j] = 0;
    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        // cout<<x<<' '<<y<<endl;
    }
    f1[1][1] = f2[1][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1 && j == 1)
                continue;
            if (a[i][j])
                continue;
            f1[i][j] += f1[i - 1][j] + f1[i][j - 1];
            f2[i][j] += f2[i - 1][j] + f2[i][j - 1];
            f1[i][j] %= mod1;
            f2[i][j] %= mod2;
        }
    }
    if (f1[n][m] == 0 && f2[n][m] == 0)
    {
        cout << 0 << '\n';
        return;
    }
    bool flag = 0;
    g1[n][m] = g2[n][m] = 1;
    for (int i = n; i >= 1; --i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (i == n && j == m)
                continue;
            if (a[i][j])
                continue;
            g1[i][j] += g1[i + 1][j] + g1[i][j + 1];
            g2[i][j] += g2[i + 1][j] + g2[i][j + 1];
            g1[i][j] %= mod1;
            g2[i][j] %= mod2;
            if (i == 1 && j == 1)
                continue;
            if (g1[i][j] * f1[i][j] % mod1 == f1[n][m])
            {
                if (g2[i][j] * f2[i][j] % mod2 == f2[n][m])
                {
                    flag = 1;
                }
            }
        }
    }
    if (flag)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
//if f[i][j]*g[i][j]==f[n][m]则为1
//超限，用mod,防止一样，可以用两个mod