#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int dir[3][2] = {1, 0, -1, 0, 0, 1};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vii> vis1(n + 2, vii(m + 2)), vis2(n + 2, vii(m + 2)), mp(n + 2, vii(m + 2)), ma(n + 2, vii(m + 2)), st(n + 2, vii(m + 2));
    // 1 朝左下走 2 朝左上走 0 无
    rep(i, 1, n)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            mp[i][j + 1] = s[j] - '0';
            if (mp[i][j + 1] == 1)
                vis1[i][j + 1] = 1, vis2[i][j + 1] = 1, ma[i][j + 1] = j + 1;
        }
    }
    for (int i = 0; i <= n + 1; i++)
        mp[i][m + 1] = 1, mp[i][0] = 1, vis1[i][m + 1] = 1, vis1[i][0] = 1, vis2[i][m + 1] = 1, vis2[i][0] = 1, ma[i][m + 1] = m + 1, ma[i][0] = 0;
    for (int i = 0; i <= m + 1; i++)
        mp[0][i] = 1, mp[n + 1][i] = 1, vis1[0][i] = 1, vis1[n + 1][i] = 1, vis2[0][i] = 1, vis2[n + 1][i] = 1, ma[0][i] = i, ma[n + 1][i] = i;
    for (int i = n; i >= 1; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (!mp[i][j])
            {
                ma[i][j] = max(ma[i + 1][j], ma[i][j + 1]);
                if (vis1[i + 1][j] && vis1[i][j + 1])
                    vis1[i][j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (!mp[i][j])
            {
                ma[i][j] = max(ma[i - 1][j], ma[i][j + 1]);
                if (vis2[i - 1][j] && vis2[i][j + 1])
                    vis2[i][j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ma[i][j] << " ";
        }
        cout << endl;
    }
    queue<pii> q;
    q.push({1, 1}), st[1][1] = 1;
    while (q.size())
    {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (mp[nx][ny] == 1 || st[nx][ny])
                continue;
            st[nx][ny] = 1, q.push({nx, ny});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << st[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m - 1; j++)
        {
            if (st[i][j] && vis1[i][j] && vis2[i][j])
            {
                if (ma[i][j] > j + k)
                {
                    cout << "YES" << endl;
                    return;
                }
                if (st[i][j - 1] && ma[i][j] > j - 1 + k)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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