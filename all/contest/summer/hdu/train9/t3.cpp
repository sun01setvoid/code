#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
//-----------------------------------------------------//
int n;
vii x(maxn), y(maxn), f(maxn);
vector<ld> th(maxn);
struct node
{
    int x, y, f;
    bool operator<(const node &t) const
    {
        if (x == t.x)
            return y < t.y;
        return x < t.x;
    }
};
ld dot(ld x1, ld y1, ld x2, ld y2)
{
    return x1 * x2 + y1 * y2;
}
ld getlen(ld x, ld y)
{
    return sqrt(dot(x, y, x, y));
}
ld getth(ld x1, ld y1, ld x2, ld y2)
{
    return pi - acos(dot(x1, y1, x2, y2) / getlen(x1, y1) / getlen(x2, y2));
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
    {
        __int128 pr = i - 1;
        if (pr == 0)
            pr = n;
        __int128 nx = i + 1;
        if (nx == n + 1)
            nx = 1;
        __int128 dx1 = x[i] - x[pr];
        __int128 dy1 = y[i] - y[pr];
        __int128 dx2 = x[nx] - x[i];
        __int128 dy2 = y[nx] - y[i];
        __int128 t1 = dx1 * dy2;
        __int128 t2 = dx2 * dy1;
        if (t1 == t2)
        {
            f[i] = 2;
            continue;
        }
        else if (t1 < t2)
            f[i] = 0;
        else
            f[i] = 1;
        th[i] = getth(dx1, dy1, dx2, dy2);
    }
    ld sum = 0;
    int ct = 0;
    vector<node> ans;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 2)
            continue;
        if (f[i] == 0)
            sum += th[i];
        else
            sum += 2 * pi - th[i];
        ans.pb({x[i], y[i], f[i]});
        ct++;
    }
    sort(ans.begin(), ans.end());
    cout << ct << endl;
    ld sumth = (ct - 2) * pi;
    if (ans[0].f == 0)
    {
        for (int i = 0; i < ct; i++)
        {
            cout << ans[i].x << " " << ans[i].y << " ";
            if (ans[i].f == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
    else
    {
        for (int i = 0; i < ct; i++)
        {
            cout << ans[i].x << " " << ans[i].y << " ";
            if (ans[i].f == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
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