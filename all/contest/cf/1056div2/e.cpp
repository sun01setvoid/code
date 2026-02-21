//d=0 mod2 是结束条件
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
int n, m, k;
void solve()
{
    cin >> n >> m >> k;
    if (n == 1)
    {
        int res = 0;
        for (int i = 1; i <= k; i++)
        {
            int x, y;
            cin >> x >> y;
            if (y == 2)
                res ^= 1;
        }
        if (res)
            cout << "Mimo" << endl;
        else
            cout << "Yuyu" << endl;
        return;
    }
    bitset<200005> a;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y - 1 != 0)
            a.flip(y - 1);
    }
    bool f = 0;
    int cnt = a.count();
    if (cnt)
        f = 1;
    if (f)
        cout << "Mimo" << endl;
    else
        cout << "Yuyu" << endl;
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