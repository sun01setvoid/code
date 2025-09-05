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
const int z = 2e5 + 10;
const int zz = 2e5;
const int B = 50000;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vii p(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cin >> p[i], cnt += (p[i] == i);
    if (n == 3)
    {
        if (p[1] == 3 && p[2] == 1 && p[3] == 2 && s == "Bob" || p[1] == 2 && p[2] == 3 && p[3] == 1 && s == "Bob" )
        {
            cout << "Alice\n";
            return;
        }
    }
    cnt = n - cnt;
    if (n == 2)
        cout << "Alice\n";
    else if (s == "Alice")
    {
        if (cnt == 2)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    else
    {
        cout << "Bob\n";
    }
}
signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}