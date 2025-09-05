/*
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
#include <set>
#include <map>
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
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
using namespace std;
int a[14];
int sum = 0;
//-----------------------------------------------------//
bool check(int x) {
    int A = 0,B=0;
    for (int i = 1;i <= 13;i++) {
        int l = max(0ll,(a[i] - sum + 3 * x + 1) / 2), r = a[i] / 3;
        if (l > r) return false;
        A += l, B += r;
    }
    if (A <= x && x <= B) return true;
    return false;
}
void solve()
{
    sum = 0;
    for (int i = 1;i <= 13;i++) cin >> a[i],sum+=a[i];
    int l = 0,r=sum/4;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
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
*/
