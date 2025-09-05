#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 4e2 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, m, a[maxn], mx, mn, ans;
int na, nb;
void dfs(int now, int prmx, int prmn, int cnt, int f)
{
    // debug(now);debug(cnt);debug(prmx);debug(prmn);debug(f);
    if (cnt >= ans)
        return;
    if (now > n)
    {
        if (f)
            cnt += prmx - prmn;
        ans = min(ans, cnt);
        return;
    }
    int t = na - a[now];
    if (f)
    {
        if (t >= prmx)
            dfs(now + 1, t, prmn, cnt, f);
        else
            dfs(now + 1, 0, t, cnt + prmx - prmn, 0);
    }
    else
    {
        if (t <= prmn)
            dfs(now + 1, prmx, t, cnt, f);
        else
            dfs(now + 1, t, prmn, cnt, 1);
    }
    if (nb >= a[now] && m == 2)
    {
        t = nb - a[now];
        if (f)
        {
            if (t >= prmx)
                dfs(now + 1, t, prmn, cnt, f);
            else
                dfs(now + 1, 0, prmx, cnt + prmx - prmn, 0);
        }
        else
        {
            if (t <= prmn)
                dfs(now + 1, prmx, t, cnt, f);
            else
                dfs(now + 1, t, prmn, cnt, 1);
        }
    }
}
void solve()
{
    // debug(1);
    cin >> n >> m;
    mx = 0;
    ans = INF;
    mn = INF;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);
    if (m == 1)
    {
        na = mx;
        nb = mx;
        dfs(1, 0, 0, 0, 1);
        cout << ans << endl;
    }
    else
    {
        for (int i = mn; i <= mx; i++)
        {
            na = mx;
            nb = i;
            dfs(1, 0, 0, 0, 1);
            //cout << i << " " << ans << endl;
        }
        cout << ans << endl;
    }
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