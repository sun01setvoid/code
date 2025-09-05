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
const int maxn = 2e5 + 5;
const int maxm = 2e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
};
int n, k, fa[maxn], dep[maxn];
vector<bitset<300>> g;
vii mp[maxn];
void dfs(int u, int pa)
{
    fa[u] = pa;
    dep[u] = dep[pa] + 1;
    for (int v : mp[u])
    {
        if (v == pa)
            continue;
        dfs(v, u);
    }
}
vii path(int x, int y)
{
    vii res;
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x] != dep[y])
    {
        res.pb(x);
        x = fa[x];
    }
    while (x != y)
    {
        res.pb(x);
        res.pb(y);
        x = fa[x];
        y = fa[y];
    }
    res.pb(x);
    return res;
}
void Raze()
{
    cin >> n >> k;
    vii u, v;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        mp[u].pb(v);
        mp[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            auto p = path(i, j);
            if (p.size() == k + 1)
            {
                bitset<300> tmp;
                for (auto x : p)
                    if (x > 1)
                        tmp.set(x - 2);
                g.pb(tmp);
                u.pb(i);
                v.pb(j);
            }
        }
    }
    for (int c = 0; c < n - 1; c++)
    {
        int p = -1;
        for (int r = c; r < g.size(); r++)
        {
            if (g[r][c])
            {
                p = r;
                break;
            }
        }
        if (p == -1)
        {
            NO;
            return;
        }
        if (p > c)
            swap(g[p], g[c]), swap(u[p], u[c]), swap(v[c], v[p]);
        for (int r = c + 1; r < g.size(); r++)
        {
            if (g[r][c])
                g[r] ^= g[c];
        }
    }
    YES;
    cout << "? " << n - 1;
    for (int i = 0; i < n - 1; i++)
        cout << " " << u[i] << " " << v[i];
    cout << endl;
    cout.flush();
    vii b(n - 1);
    vector<vii> gs(n - 1, vii(n));
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        b[i] = x;
        auto p = path(u[i], v[i]);
        g[i] ^= g[i];
        for (auto x : p)
            if (x > 1)
                g[i].set(x - 2);
    }
    for (int c = 0; c < n - 1; c++)
    {
        int p = -1;
        for (int r = c; r < n - 1; r++)
        {
            if (g[r][c])
            {
                p = r;
                break;
            }
        }
        if (p > c)
            swap(g[p], g[c]);
        for (int r = c + 1; r < n - 1; r++)
        {
            if (g[r][c])
                g[r] = g[r] ^ g[c], b[r] = b[r] ^ b[c];
        }
    }
    for (int r = n - 2; r >= 0; r--)
    {
        for (int j = r - 1; j >= 0; j--)
        {
            if (g[j][r])
                b[j] ^= b[r];
        }
    }
    cout << "!";
    for (int i = 0; i < n - 1; i++)
        cout << " " << b[i];
    cout << endl;
    cout.flush();
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