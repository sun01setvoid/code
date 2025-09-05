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
const int maxn = 1e5 + 10;
const int maxm = 1e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//

struct oo
{

};
int n, w[maxn]; vii mp[maxn];
map<int, int>mp1[maxn],mp2[maxn];
int ans=0;
void dfs(int u, int fa)//u为起点往子树走的一条链
{
    for (int v : mp[u])
    {
        if (v == fa)   continue;
        dfs(v, u);
        if (w[v]==w[u]) {
            ans+=2;
        }
        else if (mp1[v].count(w[u])) ans+=mp1[v][w[u]]*2;
        for (auto it : mp1[v]) {
            if (w[u]>it.fi) mp1[u][it.fi] += it.so;
        }
        if (w[v] < w[u])    mp1[u][w[v]]++;
    }
}
void dfs1(int u, int fa)//u为起点往父节点走再往另一子树走的双链
{
    for (int v : mp[u])
    {
        if (v == fa)continue;
        if (w[u]>w[v]){
            if (mp1[u].count(w[v])) ans+=mp1[u][w[v]]-1;
            if (mp2[u].count(w[v])) ans+=mp2[u][w[v]];
        }
        for (auto it : mp1[u]) {
            if (w[v]>it.fi){
                mp2[v][it.fi] = it.so-(mp1[v].count(it.fi)?mp1[v][it.fi]:0);
                if (mp2[u].count(it.fi)) mp2[v][it.fi]+=mp2[u][it.fi];
            }
        }
        dfs1(v, u);
    }
}
void Raze()
{
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> w[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        mp[u].pb(v); mp[v].pb(u);
    }
    ans=0;
    dfs(1, 0);
    dfs1(1, 0);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    //cin >> _;
    while (_--)Raze(); return 0;
}
/*
6
3 4 4 3 3 3
1 2
2 3
2 4
2 5
3 6
*/