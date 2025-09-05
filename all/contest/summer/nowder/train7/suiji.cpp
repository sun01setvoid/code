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
using uint = unsigned long long;
std::mt19937 eng(std::chrono::steady_clock::now().time_since_epoch().count());
uint rnd(uint l = 1ull, uint r = ~0ull) { return std::uniform_int_distribution<uint>(l, r)(eng); }
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
const int z = 4e5 + 10;
const int zz = 4e5;
const int B = 2000;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
void solve()
{
    int a = rnd() % 10000000000000000 + 1;
    int b = rnd() % 10000000000000000 + 1;
    int c = rnd() % 10000000000000000 + 1;
    int d = rnd() % 10000000000000000 + 1;
    cout << a << " " << b << " " << " " << c << " " << d << endl;
}
signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    cout << t << endl;
    while (t--)
        solve();
}
