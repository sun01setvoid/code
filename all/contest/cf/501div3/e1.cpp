#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
char mp[110][110];
bool vis[110][110];
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
            if (ck(i, j) && mp[i][j] == '*')
            {
                int len = 1;
                vis[i][j] = 1;
                vis[i + 1][j] = vis[i - 1][j] = vis[i][j + 1] = vis[i][j - 1] = 1;
                for (int k = 2; j - k >= 1 && j + k <= m && i - k >= 1 && i + k <= n; k++)
                {
                    if (mp[i - k][j] == '*' && mp[i + k][j] == '*' && mp[i][j + k] == '*' && mp[i][j - k] == '*')
                    {
                        len++;
                        vis[i - k][j] = vis[i + k][j] = vis[i][j + k] = vis[i][j - k] = 1;
                    }
                    else
                        break;
                }
                ans.push_back({i, j, len});
            }
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