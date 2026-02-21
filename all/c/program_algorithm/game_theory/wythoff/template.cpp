#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int a[5][5];
int s[5][5];
int k;
int dfs(int f)
{
    if (f == 2 * k + 1)
        return 0;
    int sum;
    if (f & 1)
    {
        sum = 0;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                int res = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
                swap(a[i + 1][j], a[i + 1][j + 1]);
                swap(a[i][j], a[i + 1][j]);
                swap(a[i][j], a[i][j + 1]);
                sum = max(res + dfs(f + 1), sum);
                swap(a[i][j], a[i][j + 1]);
                swap(a[i][j], a[i + 1][j]);
                swap(a[i + 1][j], a[i + 1][j + 1]);
            }
        }
    }
    else
    {
        sum = inf;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                int res = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
                swap(a[i + 1][j], a[i + 1][j + 1]);
                swap(a[i][j], a[i + 1][j]);
                swap(a[i][j], a[i][j + 1]);
                sum = min(res + dfs(f + 1), sum);
                swap(a[i][j], a[i][j + 1]);
                swap(a[i][j], a[i + 1][j]);
                swap(a[i + 1][j], a[i + 1][j + 1]);
            }
        }
    }
    return sum;
}
void solve()
{
    cin >> k;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
    }
    cout << dfs(1) << endl;
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}