#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i, st, en) for (int i = (st); i > (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)         \
    cout << #a << "=[";   \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "]\n"
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
const int maxn = 1e5 + 10;
const int maxm = 1e3 + 10;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int stk[maxn];
int n;
//-----------------------------------------------------//
bool check(int x, vii &a)
{
    int top = 0;
    rep(i, 1, n)
    {
        stk[++top] = (a[i]<x)?0:1;
        int cnt = 0;
        bool f = 0;
        if (top >= 3)
        {
            for (int j = top - 2; j <= top; j++)
            {
                if (stk[j] == 0)
                    cnt++;
            }
            if (cnt == 3)
            {
                top -= 3;
                stk[++top] = 0;
                continue;
            }
            if (stk[top - 2] == 0 && stk[top - 1] == 0 && stk[top] == 1)
            {
                top -= 3;
                stk[++top] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= top; i++)
    {
        if (stk[i] == 0)
            ans++;
    }
    if (top >= 2 * ans)
        return 1;
    else
        return 0;
}
void solve()
{
    cin >> n;
    vii a(n + 1);
    int l = INF, r = 0;
    rep(i, 1, n) cin >> a[i], l = min(a[i], l), r = max(a[i], r);
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid, a))
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << r << endl;
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