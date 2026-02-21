//P2397  yyy loves Maths VI  神
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n;
    cin >> n;
    // 让其他的去和多的抵消
    int cnt = 0;
    int y;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (cnt == 0)
        {
            y = x;
            cnt++;
        }
        else
        {
            if (y == x)
                cnt++;
            else
                cnt--;
        }
    }
    cout << y << endl;
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