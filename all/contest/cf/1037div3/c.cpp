#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i, st, en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for (auto x : a) cout << x << " "; \
    cout << "]\n"
#define debugarr(a, st, en)             \
    cerr << #a << "=[";                \
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

void solve() {
    int n, k;
    cin >> n >> k;
    vii a(n);
    int ma=0;
    for (auto &x : a) cin >> x,ma=max(ma,x);
    int g = a[k-1];
    if (g == ma) {
        cout << "YES" << endl;
        return;
    }
    vii v = a;
    sort(v.begin(), v.end());
    vii vc;
    vc.pb(v[0]);
    rep(i, 1, n-1) {
        if (v[i] != v[i-1]) {
            vc.pb(v[i]);
        }
    }
    int pos = 0;
    while (pos < vc.size() && vc[pos] < g) {
        pos++;
    }
    bool f = true;
    rep(i, pos, (int)vc.size()-2) {
        if (vc[i+1] - vc[i] > g) {
            f = false;
            break;
        }
    }
    cout << (f ? "YES" : "NO") << endl;
}

signed main() {
    IOS;
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}