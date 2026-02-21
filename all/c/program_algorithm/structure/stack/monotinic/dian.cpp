// P13889
// 理想的正方形
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
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
const int mod = 998244353;
const double eps = 1e-7;
//-----------------------------------------------------//
int mp[1010][1010];
int ma[1010][1010], mi[1010][1010];
void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        deque<int> q1, q2;
        for (int j = 1; j <= m; j++)
        {
            if (q1.size() && j - q1.front() >= b)
                q1.pop_front();
            if (q2.size() && j - q2.front() >= b)
                q2.pop_front();
            while (q1.size() && mp[i][q1.back()] < mp[i][j])
                q1.pop_back();
            while (q2.size() && mp[i][q2.back()] > mp[i][j])
                q2.pop_back();
            q1.push_back(j);
            q2.push_back(j);
            ma[i][j] = mp[i][q1.front()];
            mi[i][j] = mp[i][q2.front()];
        }
    }
    int ans = 0;
    for (int i = b; i <= m; i++)
    {
        deque<int> q1, q2;
        for (int j = 1; j <= n; j++)
        {
            if (q1.size() && j - q1.front() >= a)
                q1.pop_front();
            if (q2.size() && j - q2.front() >= a)
                q2.pop_front();
            while (q1.size() && ma[q1.back()][i] < ma[j][i])
                q1.pop_back();
            while (q2.size() && mi[q2.back()][i] > mi[j][i])
                q2.pop_back();
            q1.push_back(j);
            q2.push_back(j);
            if (j >= a)
                ans = (ans + ma[q1.front()][i] * mi[q2.front()][i]) % mod;
        }
    }
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