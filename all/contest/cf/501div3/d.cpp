#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
    int n, k, s;
    cin >> n >> k >> s;
    if (k * (n - 1) >= s && k <= s)
    {
        cout << "YES" << endl;
        int cnt = s - k;
        int st = 1;
        for (int i = 1; i <= k; i++)
        {
            int mar = n - st;
            int mal = st - 1;
            if (mar > mal)
            {
                int step = min(n - st - 1, cnt);
                cnt -= step;
                st += step + 1;
                cout << st << " ";
            }
            else
            {
                int step = min(st - 2, cnt);
                cnt -= step;
                st -= step + 1;
                cout << st << " ";
            }
        }
    }
    else
        cout << "NO";
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