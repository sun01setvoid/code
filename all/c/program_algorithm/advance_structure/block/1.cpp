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
int len, a[maxn], add[maxn], sum[maxn];
int get(int i)
{
    return i / len;
}
int q(int l, int r)
{
    int ans = 0;
    if (get(l) == get(r))
    {
        for (int i = l; i <= r; i++)
        {
            ans += a[i] + add[get(i)];
        }
    }
    else
    {
        int i = l, j = r;
        while (get(i) == get(l))
            ans += a[l] + add[get(l)], l++;
        while (get(j) == get(r))
            ans += a[r] + add[get(r)], r--;
        for (int i = get(l); i <= get(r); i++)
            ans += sum[i];
    }
    return ans;
}
void upd(int l, int r, int val)
{
    if (get(l) == get(r))
    {
        for (int i = l; i <= r; i++)
            a[i] += val, sum[get(i)] += val;
    }
    else
    {
        int i = l, j = r;
        while (get(l) == get(i))
            a[l] += val, sum[get(l)] += val, l++;
        while (get(r) == get(j))
            a[r] += val, sum[get(r)] += val, r--;
        for (int i = get(l); i <= get(r); i++)
            add[i] += val, sum[i] += len * val;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[get(i)] += a[i];
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << q(l, r) << endl;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            upd(l, r, x);
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