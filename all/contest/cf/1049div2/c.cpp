#include <bits/stdc++.h>
using namespace std;
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
void solve()
{
    int n;
    cin >> n;
    vii a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i % 2 == 1)
            sum += a[i];
        else
            sum -= a[i];
    }
    int pos1 = (n + 1) / 2, pos2 = n / 2;
    int d1 = max(2 * (pos1 - 1), 0ll), d2 = max(2 * (pos2 - 1), 0ll);
    int d = max(d1, d2);
    vii le(pos2 + 1), ri(pos2 + 1), pre(pos2 + 1, -INF), suf(pos2 + 2, -INF);
    pre[0] = -INF, suf[pos2 + 1] = -INF;
    for (int i = 1; i <= pos2; i++)
    {
        int j = 2 * i;
        le[i] = 2 * a[j] - j, ri[i] = 2 * a[j] + j;
        pre[i] = max(pre[i - 1], le[i]);
    }
    for (int i = pos2; i >= 1; i--)
    {
        suf[i] = max(suf[i + 1], ri[i]);
    }
    int del = d;
    for (int i = 1; i <= pos1; i++)
    {
        int g = 2 * i - 1;
        int c1 = -INF, c2 = -INF;
        if (i - 1 >= 1)
            c1 = pre[i - 1] + g;
        if (i <= pos2)
            c2 = suf[i] - g;
        int res = max(c1, c2);
        if (res != -INF)
        {
            int tmp = res - 2 * a[g];
            del = max(del, tmp);
        }
    }
    cout << sum + max(0ll, del) << endl;
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