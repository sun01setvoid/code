
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int dp1[maxn][20][2], dp2[maxn][20][2];
int a[maxn];
int n, K;
vector<vii> adj(maxn);
void dfs1(int u, int fa)
{
    dp1[u][0][0] = a[u];
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        dfs1(v, u);
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int nj = j, nk = k;
                nj++;
                if (nj == K)
                    nj = 0, nk ^= 1;
                dp1[u][nj][nk] ^= dp1[v][j][k];
            }
        }
    }
}
int tmp[25][2];
void dfs2(int u, int fa)
{
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int nj = j, nk = k;
                nj++;
                if (nj == K)
                    nj = 0, nk ^= 1;
                tmp[nj][nk] = dp1[u][nj][nk] ^ dp1[v][j][k];
            }
        }
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int nj = j, nk = k;
                nj++;
                if (nj == K)
                    nj = 0, nk ^= 1;
                dp2[v][nj][nk] ^= tmp[j][k] ^ dp2[u][j][k];
            }
        }
        dfs2(v, u);
    }
}
void solve()
{
    cin >> n >> K;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs1(1, 0);
    dfs2(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        for (int j = 0; j < K; j++)
        {
            // cout << dp1[i][j][1] << " " << dp2[i][j][1] << endl;
            ans = ans ^ dp1[i][j][1] ^ dp2[i][j][1];
        }
        if (ans)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}