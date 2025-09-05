//查多个区间的可能性，固定右端点存前缀和，就可以查询区间和了
//med 1的数量大于-1的数量
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define repi(i, l, r) for (int i = (l); i <= (r); ++i)
#define repir(i, l, r, c) for (int i = (l); i <= (r); i += (c))
#define per(i, l, r) for (int i = (l); i >= (r); --i)
#define perir(i, l, r, c) for (int i = (l); i >= (r); i -= (c))
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

ll t, n, m, k, tmp, ans, res, cnt, val;
ll arr[maxn];
stack<ll> sta;
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }
bool check(ll x, ll mi){
    tmp = 0, val = INF;
    while (!sta.empty())
        sta.pop();
    sta.push(0);
    rep1(i, n){
        if (arr[i] >= x)
            tmp++;
        else
            tmp--;
        if (arr[i] == mi){
            while (!sta.empty()){
                val = min(val, sta.top());
                sta.pop();
            }
        }
        if (val <= tmp)
            return true;
        sta.push(tmp);
    }
    return false;
}

int main()
{
    IOS;
    cin >> t;
    while (t--){
        cin >> n;
        rep1(i, n) cin >> arr[i];
        ans = 0;
        rep1(mi, min(100, n)){
            res = 0;
            ll l = 1, r = min(100, n);
            while (l <= r){
                ll mid = (l + r) >> 1;
                if (check(mid, mi)){
                    res = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            ans = max(ans, res - mi);
        }
        cout << ans << endl;
    }
    return 0;
}