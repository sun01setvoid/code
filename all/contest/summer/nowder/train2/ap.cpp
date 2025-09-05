#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 10;
const int maxm = 1e1 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{

};
int n, a[maxn]; int fac[maxn];
void Raze()
{
    cin >> n; int cnt = 0;
    for (int i = 1; i <= n; i++)cin >> a[i];
    vector<vii>dp(n + 1, vii(2, 0));
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            if (a[i - 1] == 1)
            {
                dp[i][1] = dp[i - 1][1];
            }
            else if (a[i - 1] == 0)
            {
                dp[i][1] = (dp[i - 1][0] + fac[cnt]) % mod;
            }
            else
            {
                dp[i][1] = (dp[i - 1][1] + dp[i - 1][0] + fac[cnt - 1]) % mod;
            }
        }
        else if(a[i]==0)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        }
        else
        {
            if (a[i - 1] == 1)
            {
                dp[i][1] = dp[i - 1][1];
                dp[i][0] = dp[i - 1][1];
            }
            else if (a[i - 1] == 0)
            {
                dp[i][1] = (dp[i - 1][0] + fac[cnt]) % mod;
                dp[i][0] = dp[i - 1][0];
            }
            else
            {
                dp[i][1] = (dp[i - 1][1] + dp[i - 1][0] + fac[cnt - 1]) % mod;
                dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
            }
            cnt++;
        }
    }
    cout << (dp[n][1] + dp[n][0]) % mod << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    fac[0] = 1; for (int i = 1; i < maxn; i++)fac[i] = (fac[i - 1] * 2) % mod;
    cin >> _;
    while (_--)Raze(); return 0;
}
