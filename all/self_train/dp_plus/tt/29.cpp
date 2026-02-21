//洛谷 拆分
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define ll long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const double eps = 1e-7;
//-----------------------------------------------------//
int pos1[maxn];
int pos2[maxn];
void solve()
{
    ll n;
    cin >> n;
    vector<ll> facs;
    for (int i = 1; (ll)i * i <= n; i++)
    {
        if (n % i == 0)
        {
            facs.pb(i);
            if (i != n / i)
                facs.pb(n / i);
        }
    }
    sort(facs.begin(), facs.end());
    int sz = facs.size();
    for (int i = 0; i < sz; i++)
    {
        if (n / facs[i] < facs[i])
            pos2[n / facs[i]] = i;
        else
            pos1[facs[i]] = i;
    }
    vector<vii> dp(2, vii(sz + 1, 0));
    dp[0][0] = 1;
    int st = 1;
    for (int i = 1; i <= sz - 2; i++)
    {
        dp[st] = dp[st ^ 1];
        for (int j = 0; j <= sz - 2; j++)
        {
            if (n % (facs[j] * facs[i]) != 0) continue;
            int pos;
            if (n / (facs[j] * facs[i]) < facs[j] * facs[i])
                pos = pos2[n / (facs[j] * facs[i])];
            else
                pos = pos1[facs[j] * facs[i]];
            dp[st][pos] = ((ll)dp[st][pos] + dp[st ^ 1][j]) % mod;
        }
        st ^= 1;
    }
    st ^= 1;
    cout << dp[st][sz - 1] << endl;
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