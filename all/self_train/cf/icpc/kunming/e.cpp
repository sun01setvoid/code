#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
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
const int maxn = 1e6 + 5;
const int maxm = 2e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    
};
int n, k, ans[maxn], p[maxn], d, now; vii mp[maxn]; vector<pii>tmp;
int dep[maxn], able[maxn], tot, f = 0, pa[maxn][3], f2 = 0, id[maxn];
int u1 = -1, u2 = -1;
void init() 
{ 
    for (int i = 1; i <= n; i++)
        mp[i].clear(), able[i] = 0; 
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            pa[i][j] = 0; now = 0;
}
void pt()
{
    cout << "! "; for (int i = 1; i <= n; i++)cout << ans[i] << " "; cout << endl; cout.flush();
}
void q(int x, vector<pii>& tmp)
{
    cout << "? " << x << " ";
    for (int i = 0; i < tmp.size(); i++)cout << tmp[i].fi << " " << tmp[i].so << " ";
    cout << endl; cout.flush();
    for (int i = 1; i <= x; i++)cin >> p[i];
}
void dfs(int u, int fa)
{
    if (pa[u][1])tmp.pb({ u,pa[u][1] }), id[u] = ++now;
    for (int v : mp[u])
    {
        if (v == fa)continue;
        dep[v] = dep[u] + 1;
        pa[v][0] = u;
        for (int i = 1; i < 3; i++)pa[v][i] = pa[u][i - 1];
        dfs(v, u);
    }
}
void dfs2(int u, int fa)
{
    for (int v : mp[u])
    {
        if (v == fa)continue;
        tmp.pb({ u,v });
        dfs(v, u);
    }
}
void dfs3(int u, int fa)
{
    for (int v : mp[u])
    {
        if (v == fa)continue;
        ans[v] = ans[u] ^ p[++tot];
        dfs3(v, u);
    }
}
void dfs4(int u, int fa)
{
    int cnt = 0;
    for (int v : mp[u])
    {
        if (v == fa)continue;
        if (able[v])cnt++;
    }
    if (cnt >= 2 && !f)
    {
        f = 1; d = dep[u];
        for (int v : mp[u])
        {
            if (v == fa)continue;
            if (able[v])
            {
                if (u1 == -1)u1 = v;
                else if (u2 == -1)u2 = v;
            }
        }
        tmp.pb({ u1,u2 });
    }
}
void dfs5(int u, int fa)
{
    
}
void Raze()
{
    cin >> n >> k; init();
    tmp.clear(); tot = 0; f = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        mp[u].pb(v); mp[v].pb(u);
    }
    if (k > 2)
    {
        NO; return;
    }
    if (k == 1)
    {
        YES;
        dfs2(1, 0); q(n - 1, tmp);
        dfs3(1, 0); pt(); return;
    }
    dep[1] = 0; dfs(1, 0);
    for (int i = 1; i <= n; i++)
        if (dep[i] % (k + 1) == 0)able[i] = 1;
    dfs4(1, 0);
    if (!f) { NO; return; }
    YES; int len = tmp.size();
    q(len, tmp);
    int x = u1; int val1 = 0, val2 = 0;
    while (dep[x] > 0)
    {
        val1 ^= p[id[x]];
        x = pa[x][0];
        val1 ^= p[id[x]];
        x = pa[x][2];
    }
    x = u2;
    while (dep[x] > 0)
    {
        val2 ^= p[id[x]];
        x = pa[x][0];
        val2 ^= p[id[x]];
        x = pa[x][2];
    }

}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}