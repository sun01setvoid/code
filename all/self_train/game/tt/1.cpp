// nowder Calendar Game
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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int vis[2][120][370];
bool st[120];
int cnt[15] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int pre[15] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int y)
{
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}
//看错了，实际两人的胜利条件一样
int sg(int id, int y, int m, int d)
{
    // debug(id);
    // debug(y);
    // debug(d);
    if (y == 102 && d > 309 || y > 102)
        return 1;
    if (y == 102 && d == 309)
        return 0;
    if (vis[id][y][d] != -1)
        return vis[id][y][d];
    int t;
    if (d == 29)
    {
        t = sg(id ^ 1, y, m, d + 1);
        if (!t)
            return vis[id][y][d] = 1;
        if (check(y + 1899))
        {
            t = sg(id ^ 1, y, m + 1, d + 31);
            if (!t)
                return vis[id][y][d] = 1;
        }
    }
    else if (d == 59)
    {
        if (check(y + 1899))
        {
            t = sg(id ^ 1, y, m, d + 1);
            if (!t)
                return vis[id][y][d] = 1;
        }
        else
        {
            t = sg(id ^ 1, y, m + 1, d + 2);
            if (!t)
                return vis[id][y][d] = 1;
        }
        t = sg(id ^ 1, y, m + 1, d + 29);
        if (!t)
            return vis[id][y][d] = 1;
    }
    else if (d == 366)
    {
        t = sg(id ^ 1, y + 1, 1, 1);
        if (!t)
            return vis[id][y][d] = 1;
        t = sg(id ^ 1, y + 1, 1, 31);
        if (!t)
            return vis[id][y][d] = 1;
    }
    else if (m == 12)
    {
        t = sg(id ^ 1, y, m, d + 1);
        if (!t)
            return vis[id][y][d] = 1;
        t = sg(id ^ 1, y + 1, 1, d + 31 - 366);
        if (!t)
            return vis[id][y][d] = 1;
    }
    else
    {
        int tm = d - pre[m - 1];
        if (tm <= cnt[m + 1])
        {
            t = sg(id ^ 1, y, m + 1, d + cnt[m]);
            if (!t)
                return vis[id][y][d] = 1;
        }
        if (tm == cnt[m])
        {
            t = sg(id ^ 1, y, m + 1, d + 1);
            if (!t)
                return vis[id][y][d] = 1;
        }
        else
        {
            t = sg(id ^ 1, y, m, d + 1);
            if (!t)
                return vis[id][y][d] = 1;
        }
    }
    return vis[id][y][d] = 0;
}
void solve()
{
    int y, m, d;
    cin >> y >> m >> d;
    y = y - 1899;
    d = pre[m - 1] + d;
    int t = sg(0, y, m, d);
    if (t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main()
{
    memset(vis, -1, sizeof vis);
    IOS;
    int _ = 1;
    cin >> _;
    for (int i = 1; i <= 12; i++)
        pre[i] = pre[i - 1] + pre[i];
    while (_--)
    {
        solve();
    }
    return 0;
}
/*
1. 蔡勒公式是用来计算星期的经典公式，它能够推算出给定日期是星期几。
2. 该公式的表达式为：w = (d + 2m + 3(m+1)/5 + y + y/4 - y/100 + y/400 + 1) mod 7
其中w代表星期几，d是日，m是月，y是年。
3.如果年份是世纪年（即以00结尾的年份），则需要将年份减去1再进行计算。
同时，如果月份不是大于等于3且小于等于14，则需要将这个日期视为上一年的对应月份来计算
这是因为一年的开始在蔡勒公式中被视为上一年的第13个月。
*/