// P1219 八皇后checker Challenge
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
bool vis1[50], vis2[50], col[50];
int ans, n;
vii res;
void dfs(int row)
{
    if (row == n + 1)
    {
        ans++;
        if (ans <= 3)
        {
            for (auto x : res)
                cout << x << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!col[i] && !vis1[row + i] && !vis2[row - i + n])
        {
            col[i] = vis1[row + i] = vis2[row - i + n] = 1;
            res.pb(i);
            dfs(row + 1);
            col[i] = vis1[row + i] = vis2[row - i + n] = 0;
            res.pop_back();
        }
    }
    return;
}
void solve()
{
    cin >> n;
    dfs(1);
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