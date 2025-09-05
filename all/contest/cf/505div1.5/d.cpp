#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 7e2 + 5;
const int maxm = 1e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n, a[maxn];
bool dp[maxn][maxn][2];
//dp[i][j],考虑这个区间对l-1，r+1两端点的贡献，这样就可以算以中间为根的贡献
//这样明显可以使转移达到O(1),这样O(n**3)*O(1)
bool able[maxn][maxn];
void Raze()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (__gcd(a[i], a[j]) > 1)
                able[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            if (able[i][i - 1])
                dp[i][i][0] = 1;
        }
        if (i < n)
        {
            if (able[i][i + 1])
                dp[i][i][1] = 1;
        }
    }
    bool f = 0;
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            int rval = a[r + 1], lval = a[l - 1];
            for (int k = l; k <= r; k++)
            {
                bool f1 = 0, f2 = 0;
                if (k > l)
                    f1 = dp[l][k - 1][1];
                else
                    f1 = 1;
                if (k < r)
                    f2 = dp[k + 1][r][0];
                else
                    f2 = 1;
                if (f1 && f2)
                {
                    if (able[k][r + 1])
                        dp[l][r][1] = 1;
                    if (able[k][l - 1])
                        dp[l][r][0] = 1;
                    if (l == 1 && r == n)
                        f = 1;
                }
            }
        }
    }
    if (f)
        YES;
    else
        NO;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        Raze();
    return 0;
}