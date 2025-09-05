#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
char mp[maxn][maxn];
int vis[maxn][maxn];
int n, m;
bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return 0;
    else
        return 1;
}
bool ck(int x, int y)
{
    if (x + 1 > n || y + 1 > m || x - 1 < 1 || y - 1 < 1)
        return 0;
    else
    {
        if (mp[x + 1][y] == '*' && mp[x - 1][y] == '*' && mp[x][y + 1] == '*' && mp[x][y - 1] == '*')
            return 1;
        return 0;
    }
}
int pre1[maxn][maxn], pre2[maxn][maxn], pre3[maxn][maxn], pre4[maxn][maxn];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            mp[i][j] = s[j - 1];
        }
    }
    vector<array<int, 3>> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '*')
                pre1[i][j] = pre1[i][j - 1] + 1; // left
            else
                pre1[i][j] = 0;
        }
        for (int j = m; j >= 1; j--)
        {
            if (mp[i][j] == '*')
                pre2[i][j] = pre2[i][j + 1] + 1; // right
            else
                pre2[i][j] = 0;
        }
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (mp[i][j] == '*')
                pre3[i][j] = pre3[i - 1][j] + 1; // up
            else
                pre3[i][j] = 0;
        }
        for (int i = n; i >= 1; i--)
        {
            if (mp[i][j] == '*')
                pre4[i][j] = pre4[i + 1][j] + 1; // down
            else
                pre4[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ck(i, j) && mp[i][j] == '*')
            {
                // cout << pre1[i][j] << " " << pre2[i][j] << " " << pre3[i][j] << " " << pre4[i][j] << endl;
                int len = min({pre1[i][j], pre2[i][j], pre3[i][j], pre4[i][j]}) - 1;
                // cout << i << " " << j << " " << len << endl;
                ans.push_back({i, j, len});
                vis[i - len][j]++, vis[i - len][j + 1]--, vis[i + len + 1][j]--,vis[i + len + 1][j + 1]++;
                vis[i][j - len]++, vis[i][j + len + 1]--, vis[i + 1][j - len]--, vis[i + 1][j + len + 1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            vis[i][j] = vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1] + vis[i][j];
        }
    }
    bool f = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '*' && vis[i][j] == 0)
            {
                f = 0;
                break;
            }
        }
    }
    if (f)
    {
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it[0] << " " << it[1] << " " << it[2] << endl;
        }
    }
    else
        cout << -1;
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