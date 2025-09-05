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
bool cmp1(const array<int, 3>& a, const array<int, 3>&b) {
    if (a[0] !=b[0]) return a[0] <b[0];
    return a[1] <b[1];
}
bool cmp2(const array<int, 3>& a, const array<int, 3>&b) {
    return a[1] <b[1];
}
bool cmp3(const array<int, 3>& a, const array<int, 3>&b) {
    return a[1] >b[1];
}
void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
        points[i][2] = i + 1;
    }
    sort(points.begin(), points.end(), cmp1);
    vector<array<int, 3>> tmp1(points.begin(), points.begin() + n / 2);
    vector<array<int, 3>> tmp2(points.begin() + n/2, points.end());
    sort(tmp1.begin(), tmp1.end(), cmp2);
    sort(tmp2.begin(), tmp2.end(), cmp3);
    for (int i = 0; i < n/2; i++) {
        cout << tmp1[i][2] << " " << tmp2[i][2] << "\n";
    }
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