// atcoder arc208 a
//结束条件是到或的情况，异或等于T,但到底了
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
void solve()
{
    int n;
    cin >> n;
    // 考虑异或问题，异或初始为T，那么不能到T
    // 若不为T,可以通过操作到异或为T
    int s = 0, t = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        s^=x;
        t|=x;
    }
    if (s==t)
        cout << "Bob" << endl;
    else
        cout << "Alice" << endl;
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