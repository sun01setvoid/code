#include <bits/stdc++.h>
using namespace std;
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

struct node {
    int l, r, x;
};
bool cmp(node&a,node&b){
    return a.l<b.l;
}
void solve() {
    int n;
    int k;
    cin >> n >> k;
    vector<node> a(n);
    rep(i, 0, n-1) {
        cin >> a[i].l >> a[i].r >> a[i].x;
    }
    sort(a.begin(), a.end(),cmp); 
    prq <int> pq;  
    int i = 0,ans=k;
    while (true) {
        while (i < n && a[i].l <= ans) {
            pq.push(a[i].x);
            i++;
        }
        while (!pq.empty() && pq.top() <= ans) {
            pq.pop();
        }
        if (pq.empty()) break;
        ans = pq.top();
        pq.pop();
    }
    cout << ans << endl;
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