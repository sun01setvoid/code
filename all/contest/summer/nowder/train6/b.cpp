#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
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
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, y, m;
bool check(int x, vector<vii> &A)
{
    __int128 s = x;
    for (int i = 0; i < n; i++)
    {
        __int128 res = 0;
        if (A[i].size() == 1)
        {
            if (s <= A[i][0])
            {
                return false;
            }
            s = A[i][0];
            continue;
        }
        for (int j = A[i].size() - 1; j >= 0; j--)
        {
            if (s <= A[i][j])
                return false;
            else
            {
                __int128 ans = 1;
                for (int k = 1; k <= A[i].size() - 1 - j; k++)
                {
                    ans = ans * s;
                    if (ans > 2e9)
                    {
                        res = 2e9;
                        break;
                    }
                }
                if (A[i][j] * ans > 2e9 || res + A[i][j] * ans > 2e9)
                {
                    res = 2e9;
                    break;
                }
                res += A[i][j] * ans;
            }
        }
        s = res;
    }
    return s >= y;
}
bool check2(int x, vector<vii> &A)
{
    __int128 s = x;
    for (int i = 0; i < n; i++)
    {
        __int128 res = 0;
        if (A[i].size() == 1)
        {
            if (s <= A[i][0])
            {
                return false;
            }
            s = A[i][0];
            continue;
        }
        for (int j = A[i].size() - 1; j >= 0; j--)
        {
            if (s <= A[i][j])
                return false;
            else
            {
                __int128 ans = 1;
                for (int k = 1; k <= A[i].size() - 1 - j; k++)
                {
                    ans = ans * s;
                    if (ans > 2e9)
                    {
                        res = 2e9;
                        break;
                    }
                }
                if (A[i][j] * ans > 2e9 || res + A[i][j] * ans > 2e9)
                {
                    res = 2e9;
                    break;
                }
                res += A[i][j] * ans;
            }
        }
        s = res;
    }
    return s >= y + 1;
}
void solve()
{
    cin >> n >> y >> m;
    vector<vii> A(n);
    for (int i = 0; i < n; i++)
    {
        int li;
        cin >> li;
        for (int j = 0; j < li; j++)
        {
            int tmp;
            cin >> tmp;
            A[i].pb(tmp);
        }
    }
    int l = 2, r = m;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid, A))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (l > m)
    {
        cout << "-1 -1" << endl;
        return;
    }
    int ll = l, rr = m;
    while (ll <= rr)
    {
        int mid = (ll + rr) >> 1;
        if (check2(mid, A))
        {
            rr = mid - 1;
        }
        else
        {
            ll = mid + 1;
        }
    }
    if (ll - 1 < l)
    {
        cout << "-1 -1" << endl;
        return;
    }
    cout << l << " " << ll - 1 << endl;
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