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
const int maxn = 3e5 + 5;
const int maxm = 2e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{

};
int n, q, a[maxn], b[maxn], fa[maxn], up[maxn][maxm];//up父亲
vii mp[maxn]; int val[maxn][maxm], sum[maxn], id[maxn];//val到它的最小等级
void init()
{
    for (int i = 1; i <= n; i++)
        mp[i].clear(), fa[i] = 0, sum[i] = 0, id[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 0; (1ll << j) <= n; j++)
            val[i][j] = 0, up[i][j] = 0;
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool cmp(int x, int y) { return  a[x] < a[y]; }
void Raze()
{
    cin >> n >> q; init();
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];
    sort(id + 1, id + 1 + n, cmp);
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        mp[u].pb(v); mp[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
    {
        int u = id[i]; sum[u] = b[u]; fa[u] = u;
        for (int v : mp[u])
        {
            if (!fa[v])continue;
            int fv = find(v); sum[u] += sum[fv];
            fa[fv] = u; up[fv][0] = u;
            val[fv][0] = a[u] - sum[fv];
        }
    }
    for (int j = 1; (1ll << j) <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
            val[i][j] = max(val[i][j - 1], val[up[i][j - 1]][j - 1]);
        }
    }
    while (q--)
    {
        int x, y; cin >> x >> y;
        if (y < a[x]) { cout << y << endl; continue; }
        for (int j = 18; j >= 0; j--)
        {
            if (up[x][j] && val[x][j] <= y)x = up[x][j];
        }
        cout << y + sum[x] << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}
