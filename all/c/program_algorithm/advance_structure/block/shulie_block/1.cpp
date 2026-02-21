// P13976 数列分块入门1
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
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int len, a[maxn], add[maxn], be[maxn];
void upd(int l, int r, int val)
{
    if (be[l] == be[r])
    {
        for (int i = l; i <= r; i++)
            a[i] += val;
    }
    else
    {
        int i = l, j = r;
        while (be[l] == be[i])
            a[l] += val, l++;
        while (be[r] == be[j])
            a[r] += val, r--;
        for (int i = be[l]; i <= be[r]; i++)
            add[i] += val;
    }
}
void solve()
{
    int n;
    cin >> n;
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i], be[i] = i / len;
    for (int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        int l, r, c;
        cin >> l >> r >> c;
        if (op == 1)
        {
            cout << a[r] + add[be[r]] << endl;
        }
        else
        {
            upd(l, r, c);
        }
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