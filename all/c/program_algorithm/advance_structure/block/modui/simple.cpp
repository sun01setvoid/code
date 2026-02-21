#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int a[maxn];
int cnt[maxn], len, ans[maxn], be[maxn];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
struct qry
{
    int l, r, id;
    bool operator<(const qry &A) const
    {
        if (be[l] != be[A.l])
            return be[l] < be[A.l];
        return (be[l] & 1) ? r < A.r : r > A.r;
    };
};
qry q[maxn];
void solve()
{
    int n, m;
    n = read();
    int ma = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read(), ma = max(ma, a[i]);
    m = read();
    len = sqrt(n * n / m);
    for (int i = 1; i <= ma; i++)
        be[i] = i / len;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        l = read();
        r = read();
        q[i].l = l, q[i].r = r, q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    for (int t = 1, i = 1, j = 0, res = 0; t <= m; t++)
    {
        int l = q[t].l, r = q[t].r, id = q[t].id;
        while (j < r)
        {
            int x = a[++j];
            res += (!cnt[x]++);
        }
        while (j > r)
        {
            int x = a[j--];
            res -= (cnt[x]-- == 1);
        }
        while (i > l)
        {
            int x = a[--i];
            res += (!cnt[x]++);
        }
        while (i < l)
        {
            int x = a[i++];
            res -= (cnt[x]-- == 1);
        }
        ans[id] = res;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
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