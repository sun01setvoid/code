#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ls p << 1
#define rs p << 1 | 1
#define fi first
#define se second
#define pa pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
/*
        _/_/_/     _/_/_/_/_/_/_/
      _/                 _/
     _/                  _/
     _/                  _/
     _/                  _/
      _/                 _/
        _/_/_/           _/
*/
// 再不卷就退役了
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
map<pa, int> mp;
int brr[6][2] = {0, -1, 1, -1, 1, 0, 0, 1, -1, 1, -1, 0};
int a[maxn], b[maxn], c[maxn], n, ans, sa, sb, sc;
int get(int x, int y)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = (sum + max(max(abs(a[i] - x), abs(b[i] - y)), abs(a[i] + b[i] - x - y)));
    }
    return sum;
}
int get1(int x, int y)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = (sum + max(max(abs(a[i] - x), abs(c[i] - y)), abs(a[i] + c[i] - x - y)));
    }
    return sum;
}
int get2(int x, int y)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = (sum + max(max(abs(a[i] - x), abs(c[i] - y)), abs(b[i] + c[i] - x - y)));
    }
    return sum;
}
void solve()
{
    cin >> n;
    mp.clear();
    sa = 0;
    sb = 0;
    sc = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        sa += a[i];
        sb += b[i];
        sc += c[i];
    }
    sa /= 2;
    sb /= 2;
    sc /= 2;
    ans = get(sa, sb);
    mp[{sa, sb}] = 1;
    queue<pa> q;
    int cnt = 1;
    q.push({sa, sb});
    while (q.size())
    {
        if (cnt >= 1000)
            break;
        auto cur = q.front();
        q.pop();
        int x = cur.fi, y = cur.se;
        for (int i = 0; i < 6; i++)
        {
            int nx = x + brr[i][0], ny = brr[i][1];
            if (mp[{nx, ny}])
                continue;
            mp[{nx, ny}] = 1;
            int t = get(nx, ny);
            ans = min(ans, t);
            q.push({nx, ny});
            cnt++;
        }
    }
    ans = min(ans, get1(sa, sc));
    mp[{sa, sc}] = 1;
    while (q.size())
        q.pop();
    cnt = 1;
    q.push({sa, sc});
    while (q.size())
    {
        if (cnt >= 1000)
            break;
        auto cur = q.front();
        q.pop();
        int x = cur.fi, y = cur.se;
        for (int i = 0; i < 6; i++)
        {
            int nx = x + brr[i][0], ny = brr[i][1];
            if (mp[{nx, ny}])
                continue;
            mp[{nx, ny}] = 1;
            int t = get1(nx, ny);
            ans = min(ans, t);
            q.push({nx, ny});
            cnt++;
        }
    }
    ans = min(ans, get2(sb, sc));
    mp[{sb, sc}] = 1;
    while (q.size())
        q.pop();
    cnt = 1;
    q.push({sb, sc});
    while (q.size())
    {
        if (cnt >= 1000)
            break;
        auto cur = q.front();
        q.pop();
        int x = cur.fi, y = cur.se;
        for (int i = 0; i < 6; i++)
        {
            int nx = x + brr[i][0], ny = brr[i][1];
            if (mp[{nx, ny}])
                continue;
            mp[{nx, ny}] = 1;
            int t = get2(nx, ny);
            ans = min(ans, t);
            q.push({nx, ny});
            cnt++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}