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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
void solve()
{
    int n = rand() % 1000 + 1000, q = rand() % 1000 + 3000;
    cout << n << " " << q << endl;
    for (int i = 1; i <= n; i++)
        cout << "0 ";
    cout << endl;
    for (int i = 1; i <= q; i++)
    {
        int op = rand() % 4 + 1;
        if (op == 1 || op == 2)
        {
            int x = rand() % n + 1, k = rand() % 1000 + 10;
            cout << op << " " << x << " " << k << endl;
        }
        else
        {
            int x = rand() % n + 1;
            cout << op << " " << x << endl;
        }
    }
}
signed main()
{
    IOS;
    srand(time(0));
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}