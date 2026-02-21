// POI2014 PTA-Little Brid
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
int q[maxn], q1[maxn], q2[maxn];
int a[maxn], dp[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int qr;
    cin >> qr;
    for (int i = 1; i <= qr; i++)
    {
        int k;
        cin >> k;
        int hh = 0, tt = -1;
        q[++tt] = 1;
        q1[tt] = 0;
        q2[tt] = a[1];
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            if (hh <= tt && q[hh] < i - k)
                hh++;
            int cur = q[hh];
            if (a[cur] <= a[i])
                dp[i] = dp[cur] + 1;
            else
                dp[i] = dp[cur];
            while (hh <= tt && q1[tt] > dp[i] || (q1[tt] == dp[i] && q2[tt] < a[i]))
                tt--;
            q[++tt] = i;
            q1[tt] = dp[i], q2[tt] = a[i];
        }
        cout << dp[n] << endl;
    }
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