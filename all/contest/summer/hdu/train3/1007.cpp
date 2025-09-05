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
using uint = unsigned long long;
std::mt19937 eng(std::chrono::steady_clock::now().time_since_epoch().count());
uint rnd(uint l = 1ull, uint r =~0ll) { return std::uniform_int_distribution<uint>(l, r)(eng); }
//-----------------------------------------------------//
void solve()
{
    int n;
    cin >> n;
    vector <pii> a(n+1);
    vii b(n + 1);
    set <int> s;
    rep(i, 1, n) {
        int l, r;
        cin >> l >> r;
        a[i] = { l,r };
        b[i] = rnd();
        s.insert(l);
        s.insert(r + 1);
    }
    map <int, int> mp;
    int cnt = 0;
    for (auto i = s.begin();i != s.end();i++) {
        mp[*i] = ++cnt;
    }
    vii sum(s.size() + 1);
    //vdebug(s);
    //vdebug(b);
    rep(i, 1, n) {
        int l = a[i].first, r = a[i].second;
        int pos1 = mp[l],pos2 = mp[r + 1];
        //debug(pos1);debug(pos2);
        sum[pos1] ^= b[i], sum[pos2]^=b[i];
    }
    map<int, int> ans;
    for (int i = 1;i <= s.size();i++) {
        sum[i] = sum[i] ^ sum[i - 1];
        if (sum[i]!=0) ans[sum[i]] = 1;
    }
    cout << ans.size()+1 << endl;
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