#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int d[maxn], f[maxn], p[maxn];
int n, m;
// 其实p只有n-2个不定的（p[n-1]=n）
//但是因为f有n-1个，所以遍历n-1个才能填满f,所以为了统一，采用n-1个
void tr2p()
{
    for (int i = 1; i <= n - 1; i++)
        cin >> f[i], d[f[i]]++;
    for (int i = 1, j = 1; i <= n - 1; j++)
    {
        while (d[j]) // j为当前度数为0的
            j++;
        p[i++] = f[j];
        while (i <= n - 1 && --d[p[i - 1]] == 0 && p[i - 1] < j) // 当前这一轮产生比j小的点
        {
            p[i] = f[p[i - 1]]; // 这个点的父节点等于这个点的父亲
            // 这个点是p[i-1]
            i++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n - 2; i++)
        ans ^= i * p[i];
    cout << ans << endl;
}
void p2tr()
{
    for (int i = 1; i <= n - 1; i++)
        cin >> p[i], d[p[i]]++;
    for (int i = 1, j = 1; i <= n - 1; j++)
    {
        while (d[j]) // j为当前度数为0的
            j++;
        f[j] = p[i++];
        while (i <= n - 1 && --d[p[i - 1]] == 0 && p[i - 1] < j)
        {
            f[p[i - 1]] = p[i];
            i++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++)
        ans ^= i * f[i];
    cout << ans << endl;
}
void solve()
{
    cin >> n >> m;
    p[n - 1] = n;
    if (m == 1)
        tr2p();
    else
        p2tr();
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