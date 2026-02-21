#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mn = 22 + 10;
const int mm = 2 * mn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
double a[mn], b[mn];
int c[mn];
double dp[(1 << 22) - 1];
double calc(int n)
{
    if (a[1] <= b[1])
        return a[1];
    double di = 1. / (a[1] - b[1]);
    double sum = 0.;
    for (int i = 2; i <= n; i++)
    {
        double ad = (a[i - 1] - a[i]) * di;
        if (sum + ad > 1.)
            return a[i - 1] - (1. - sum) / di;
        if (a[i] <= b[i])
            return a[i];
        sum += ad;
        di += 1. / (a[i] - b[i]);
    }
    return a[n] - (1. - sum) / di;
    // c-5x,c-3y,c-4z
    // x+y+z=d是一个常数
    // c-d*(1/5+1/3+1/4)
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);
    for (int i = 1; i < (1 << n); i++)
    {
        int tot = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (!(i >> j & 1))
                continue;
            a[++tot] = c[j];
            b[tot] = dp[i ^ (1 << j)];
        }
        dp[i] = calc(tot);
    }
    cout << setprecision(8) << dp[(1 << n) - 1];
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