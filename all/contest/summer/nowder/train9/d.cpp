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
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
bool check(string s)
{
    int y = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + s[3] - '0';
    int m = (s[4] - '0') * 10 + s[5] - '0';
    int d = (s[6] - '0') * 10 + s[7] - '0';
    if (y < 1 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return true;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return d <= 30;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return d <= 29;
    return d <= 28;
}
int ans = 0;
int n;
string s;
void dfs(int now, string num)
{
    if (num.size() == 8)
    {
        if (check(num))ans++;
        return;
    }
    if (now >= n)
        return;
    dfs(now + 1, num + s[now]);
    dfs(now + 1, num);
}
void solve()
{
    cin >> n;
    cin >> s;
    dfs(0, "");
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