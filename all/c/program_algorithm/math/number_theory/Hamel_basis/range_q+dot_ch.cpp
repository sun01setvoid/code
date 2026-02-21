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
int p[maxn][30], pos[maxn][30];
void add(int cur, int ps, int x)
{
    for (int i = 29; i >= 0; i--)
    {
        if (!(x >> i & 1))
            continue;
        if (!p[cur][i])
        {
            p[cur][i] = x;
            pos[cur][i] = ps;
            return;
        }
        else if (ps > pos[cur][i])
            swap(p[cur][i], x), swap(pos[cur][i], ps);
        x ^= p[cur][i];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
    {
        for (int j = 0; j <= 29; j++)
            p[i][j] = p[i - 1][j], pos[i][j] = pos[i - 1][j];
        cin >> x;
        add(i, i, x);
    }
    int last = 0;
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            int l, r;
            cin >> l >> r;
            l = (l ^ last) % n + 1, r = (r ^ last) % n + 1;
            if (l > r)
                swap(l, r);
            int ans = 0;
            for (int j = 29; j >= 0; j--)
            {
                if (pos[r][j] >= l)
                    ans = max(ans, ans ^ p[r][j]);
            }
            last = ans;
            cout << ans << endl;
        }
        else
        {
            int x;
            cin >> x;
            x ^= last;
            n = n + 1;
            for (int j = 0; j <= 29; j++)
            {
                p[n][j] = p[n - 1][j];
                pos[n][j] = pos[n - 1][j];
            }
            add(n, n, x);
        }
    }
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