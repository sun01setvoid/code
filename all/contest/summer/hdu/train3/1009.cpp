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
int fpow(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1)res = res * a % mod;
        a = a * a%mod;
        k >>= 1;
    }
    return res;
}
//-----------------------------------------------------//
void solve()
{
    int n, m;
    cin >> n >> m;
    vii a(n + 1), sp(n + 1);
    int st = 1, inv10 = fpow(10, mod - 2, mod);
    rep(i, 1, n) {
        cin >> a[i];
        if (a[i] != 10) {
            sp[i] = a[i] * fpow(10 - a[i], mod - 2, mod) % mod;
            st = st * (10 - a[i]) % mod * inv10 % mod; // 特殊处理
        }
    }
    // 概率转移常用st，有不使用的区间,先默认都不用，用的话就乘上去
    vii dp(n + 1,0),ma(n+1,0);
    rep(i, 1, m) {
        int l, r;
        cin >> l >> r;
        ma[r] = max(ma[r], l);
    }
    dp[0] = 1;
    int sum = 1,pt=0;
    for (int i = 1;i <= n;i++) { 
        //dp是滚动数组dp[i][j]->dp[j]维护尝试过前i个点,且1-i（内）的区间都被染色，最后在第j个点染色的概率，不乘的话就是不染i，乘的话就是染i(因为乘以全局的st,来保证)
        //所以这里只需要处理dp[i][i],也就是dp[i]
        //sum维护当前dp[i][j]中的合法方案
        if (a[i] == 10) {
            dp[i] = sum; 
            while (pt < i) {
                //sum = (sum - dp[pt] + mod) % mod;
                dp[pt] = 0;
                pt++;
            }
            //sum = (sum+dp[i])%mod;
            //其实sum不变,所以注释部分不用写
            continue;
        }//pt前的不在使用
        dp[i] = sum * sp[i]%mod;sum = (sum + dp[i]) % mod;
        while (ma[i] > pt) sum = (sum - dp[pt] + mod) % mod,dp[pt]=0, pt++;//这样一定考虑每个 dp[i][i]转移正确
        //dp[pt]=0,其实也不需要，pt前的都不在使用了
        //最后一次合理的被染色点一定是递增的
    }
    cout << st * sum % mod<< endl;
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