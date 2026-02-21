#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n;
    cin >> n;
    vector<pii> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i].fi >> vc[i].se;
    int ans = 0;
    for (auto &p : vc)
        ans += (p.se - p.fi);
    vii t1(n), t2(n), idx(n), a1(n), a2(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        t1[i] = vc[i].fi + vc[i].se;
        t2[i] = vc[i].se;
        tot += t2[i];
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](int i, int j)
         { return t1[i] < t1[j]; });
    for (int i = 0; i < n; i++)
    {
        a1[i] = t1[idx[i]];
        a2[i] = t2[idx[i]];
    }
    int tmp = -INF;
    if (n % 2 == 0)
    {
        int m = n / 2;
        int res = 0;
        for (int i = 0; i < m; i++)
            res += a1[i];
        tmp = tot - res;
    }
    else
    {
        int m = (n - 1) / 2;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + a1[i];
        if (m == 0)
            tmp = 0;
        else
        {
            tmp = -INF;
            for (int k = 0; k < n; k++)
            {
                int res = tot - a2[k], mi;
                if (k >= m)
                    mi = pre[m];
                else
                    mi = pre[m + 1] - a1[k];
                if (res - mi > tmp)
                    tmp = res - mi;
            }
        }
    }
    ans += max(0ll, tmp);
    cout << ans << endl;
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
