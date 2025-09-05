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
//#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
//const int INF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int maxn = 5e3 + 10;
const int maxm = 1e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    
};
int n, m; vii mp[maxn]; 
void init() { for (int i = 1; i <= n; i++)mp[i].clear(); }
void Raze()
{
    cin >> n >> m;
    vector<vii>dp(n * 2+1, vii(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        mp[u].pb(v); mp[v].pb(u);
    }
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = INF;
    dp[0][1] = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            int deg = i % mp[j].size();
            dp[i + 1][mp[j][deg]] = min(dp[i + 1][mp[j][deg]], dp[i][j]);
        }
    }
    init();
    for (int i = 1; i <= 2 * n; i++)
    {
        if (dp[i][n] != INF)
        {
            cout << i << " " << dp[i][n] << endl; return;
        }
    } 
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}