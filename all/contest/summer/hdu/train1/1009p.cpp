#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                 \
    rep(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a, st, en)             \
    cerr << #a << "=[";                  \
    repn(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n;
//-----------------------------------------------------//
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v, vii &tr)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tr[i] += v;
    }
}
int query(int x, vii &tr)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        ans += tr[i];
    }
    return ans;
}
void solve()
{
    n = 10;
    vii a(n + 1), tr(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    random_shuffle(a.begin() + 1, a.end());
    //debugarr(a,1,n);
    rep(i, 1, n) add(a[i], 1, tr);
    int l = 1, r = n, l1 = 1, r1 = n;
    int ans = 2;
    while (l <= n && l <= r)
    {
        if (l1 - l != 0 && (l1 - l <= r - r1 || r - r1 == 0))
        {
            rep(i, l, l1 - 1) add(a[i], -1, tr);
            l = l1;
        }
        else if (r - r1 != 0 && (l1 - l == 0 || r - r1 <= l1 - l))
        {
            drep(i, r, r1 + 1) add(a[i], -1, tr);
            r = r1;
        }
        while (l + 1 <= n && a[l] < a[l + 1])
        {
            add(a[l], -1, tr);
            l++;
        }
        l1=l;
        rep(i, l + 1, n)
        {
            if (a[i] > a[l])
            {
                l1 = i;
                break;
            }
        }
        while (r - 1 >= 1 && a[r] < a[r - 1])
        {
            add(a[r], -1, tr);
            r--;
        }
        r1=r;
        drep(i, r - 1, 1)
        {
            if (a[i] > a[r])
            {
                r1 = i;
                break;
            }
        }
        if (l >= r || (l1 == l && r1 == r))
            break;
        //debug(l);debug(r);debug(l1);debug(r1);
        ans = max(ans, query(min(a[l], a[r]) - 1, tr) + 2);
    }
    int ans1 = 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int res = 2;
            for (int k = i + 1; k < j; k++)
            {
                if (a[k] < a[i] && a[k] < a[j])
                    res++;
            }
            ans1 = max(res, ans1);
        }
    }
    if (ans1 == ans)
    {
        YES;
    }
    else
    {
        NO;
        rep(i, 1, n) cout << a[i] << " ";
        cout << endl;
        cout << "ans=" << ans << " ans1=" << ans1 << endl;
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