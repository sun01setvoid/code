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
#define eb emplace_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
bool cmp(pii A, pii B)
{
    if (A.fi != B.fi)
        return A.fi < B.fi;
    return A.se > B.se;
}
void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n + 1);
    int ax, ay, bx, by;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        if (i == 1)
        {
            ax = bx = a[i].fi, ay = by = a[i].se;
            continue;
        }
        if (abs(a[i].fi + 1e9) + abs(a[i].se - 1e9) < abs(ax + 1e9) + abs(ay - 1e9))
        {
            ax = a[i].fi, ay = a[i].se;
        }
        if (abs(a[i].fi - 1e9) + abs(a[i].se - 1e9) < abs(bx - 1e9) + abs(by - 1e9))
        {
            bx = a[i].fi, by = a[i].se;
        }
    }
    sort(a.begin() + 1, a.begin() + n + 1, cmp);
    int ans1, ans2;
    cout << "? R 1000000000" << endl;
    cout.flush();
    cin >> ans1;
    cout << "? R 1000000000" << endl;
    cout.flush();
    cin >> ans1;
    cout << "? U 1000000000" << endl;
    cout.flush();
    cin >> ans1;
    cout << "? U 1000000000" << endl;
    cout.flush();
    cin >> ans1;
    cout << "? L 1000000000" << endl;
    cout.flush();
    cin >> ans2;
    cout << "? L 1000000000" << endl;
    cout.flush();
    cin >> ans2;
    cout << "? L 1000000000" << endl;
    cout.flush();
    cin >> ans2;
    cout << "? L 1000000000" << endl;
    cout.flush();
    cin >> ans2;
    int Y = (ans1 + ans2 - 8000000000 - ax + bx + ay + by) / 2;
    int X = ans1 + bx + by - Y - 4000000000;
    cout << "! " << X << " " << Y << endl;
    cout.flush();
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