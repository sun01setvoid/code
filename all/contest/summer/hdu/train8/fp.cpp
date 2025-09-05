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
const int z = 1e5 + 10;
const int zz = 1e5;
const int B = 50000;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
int n, w;
__int128 get3(__int128 x)
{
    return x * (x + 1) * (2 * x + 1) / 6;
}
__int128 get2(__int128 x)
{
    return x * (x + 1) / 2;
}
__int128 get(__int128 del, __int128 now, __int128 t)
{
    __int128 ans = (2 * now - 1) * del * get2(t) - now * now * (t + 1) + now * (t + 1) - del * del * get3(t);
    return ans / 2 + n * now * (t + 1) - n * del * get2(t);
}
void solve()
{
    cin >> n >> w;
    __int128 ans = 0;
    __int128 now = n;
    for (__int128 del = n / w;;)
    {
        __int128 t = (now - del * w) / del;
        __int128 tt = get(del, now, t);
        // cout << "del=" << del << endl;
        // cout << "t=" << t << " tt=" << tt << endl;
        ans += tt;
        now -= (t + 1) * del;
        // cout << "now=" << now << endl;
        del = now / w;
        if (now < w)
            break;
    }
    ans += (__int128)(n - w + 2 + n) * (w - 1) / 2;
    vector<int> vc;
    while (ans)
    {
        vc.pb(ans % 10);
        ans /= 10;
    }
    for (int i = vc.size() - 1; i >= 0; i--)
        cout << vc[i];
    cout << endl;
}
signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}