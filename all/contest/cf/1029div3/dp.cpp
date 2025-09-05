#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a,st,en)             \
    cerr << #a << "=[";             \
    repn(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int int
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        v1[i] = i + 1;
        v2[i] = n - i;
    }
    bool f = true;
    int x = 0, y = 0;
    int det = 1 * (n - 1) - 2 * n;
    if (det == 0) {
        bool all_zero = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    x = (a[0] * (n - 1) - a[1] * n) / det;
    y = (a[1] * 1 - a[0] * 2) / det;
    if (x < 0 || y < 0) {
        f = false;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != x * v1[i] + y * v2[i]) {
            f = false;
            break;
        }
    }
    if (f) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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