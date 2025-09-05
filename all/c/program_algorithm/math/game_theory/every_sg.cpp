#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int n;
int f[1010][1010], step[1010][1010];
int sg(int a, int b)
{
    if (a > b)
        swap(a, b);
    if (f[a][b] != -1)
        return f[a][b];
    if (!a || !b)
        return f[a][b] = 0;
    int x = b % a, y = a, k = b / a;
    if (k == 1) // 只有一步的话，两者sg状态不同
    {
        f[a][b] = sg(x, y) ^ 1;
        step[a][b] = step[x][y] + 1;
    }
    else
    {
        f[a][b] = 1;
        if (sg(x, y))
            step[a][b] = step[x][y] + 2;
        else
            step[a][b] = step[x][y] + 1;
    }
    return f[a][b];
}
void solve()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        sg(a, b);
        ans = max(ans, step[a][b]);
    }
    cout << (ans & 1 ? "MM" : "GG") << endl;
}
signed main()
{
    IOS;
    memset(f, -1, sizeof f);
    n = 1;
    while (cin >> n)
    {
        solve();
    }
    return 0;
}