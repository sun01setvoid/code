#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
//#define int long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    int u, v, w;
}e[maxn];

// -------- 前向星存图（两套：一套用于原图连通性 bfs，另一套用于合并树的孩子列表） -----------
const int MAXV = maxn;           // 节点上界（保留 2*n 的空间）
const int MAXE = 800005;         // 足够容纳 2*m 或者合并树的边数量

int head1[MAXV], to1[MAXE], nxt1[MAXE], ec1; // input undirected graph (for BFS)
int head2[MAXV], to2[MAXE], nxt2[MAXE], ec2; // merge-tree children list (directed parent->child)

inline void add1(int u, int v) { // undirected graph
    to1[ec1] = v; nxt1[ec1] = head1[u]; head1[u] = ec1++;
}
inline void add1_bi(int u, int v) {
    add1(u, v); add1(v, u);
}
inline void add2(int u, int v) { // directed parent->child
    to2[ec2] = v; nxt2[ec2] = head2[u]; head2[u] = ec2++;
}

// ----------------------------------------------------------------------------------------

bool cmp(oo& a, oo& b) { return a.w < b.w; }
int n, m, k;
int vis_node[maxn]; // 用于 BFS 标记节点访问（代替原来混用的 vis）
int sel[maxn];      // 用于标记是否为 MST 边（代替原来的 vis[i]）
int fa[maxn], dep[maxn];
int now;
int lca[maxn][22], siz[maxn], cnt[maxn], len[maxn];

void init_head1(int up) {
    for (int i = 1; i <= up; ++i) head1[i] = -1;
    ec1 = 0;
}
void init_head2(int up) {
    for (int i = 1; i <= up; ++i) head2[i] = -1;
    ec2 = 0;
}

int bfs(int x)
{
    queue<int>q; q.push(x); vis_node[x] = 1; int ans = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int eid = head1[u]; eid != -1; eid = nxt1[eid])
        {
            int v = to1[eid];
            if (vis_node[v]) continue;
            q.push(v); vis_node[v] = 1; ans++;
        }
    }
    return ans;
}

int findfa(int x) { return fa[x] == x ? x : fa[x] = findfa(fa[x]); }
void mergeuf(int u, int v)
{
    int x = findfa(u), y = findfa(v);
    if (x != y) fa[x] = y;
}

void dfs(int u)
{
    for (int eid = head2[u]; eid != -1; eid = nxt2[eid])
    {
        int v = to2[eid];
        if (v == lca[u][0]) continue;
        lca[v][0] = u;
        dep[v] = dep[u] + 1;
        for (int j = 1; j <= 20; j++)
        {
            if (dep[v] < (1 << j)) break;
            lca[v][j] = lca[lca[v][j - 1]][j - 1];
        }
        dfs(v);
    }
}

int LCA(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; i >= 0; i--)
    {
        if (dep[lca[u][i]] >= dep[v])
            u = lca[u][i];
    }
    if (u == v) return u;
    for (int i = 20; i >= 0; i--)
    {
        if (lca[u][i] != lca[v][i])
            u = lca[u][i], v = lca[v][i];
    }
    return lca[v][0];
}

void build()
{
    now = n;
    for (int i = 1; i <= 2 * n; i++)
    {
        head2[i] = -1;
        fa[i] = i;
        siz[i] = 1;
        cnt[i] = 0;
        len[i] = 0;
    }
    ec2 = 0;

    for (int i = 1; i <= m; i++)
    {
        if (!sel[i]) continue;
        int u = findfa(e[i].u), v = findfa(e[i].v);
        now++;
        add2(now, u);
        add2(now, v); 
        fa[u] = fa[v] = now;
        cnt[now] = 0;
        siz[now] = ( (ll)siz[u] + siz[v] ) % mod;
        len[now] = e[i].w;
    }
    for (int i = 1; i <= now; i++)
        for (int j = 0; j <= 20; j++)
            lca[i][j] = 0, dep[i] = 0;
    dep[now] = 1; lca[now][0] = 0;
    for (int j = 1; j <= 20; j++) lca[now][j] = 0;
    dfs(now);

    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v;
        int w = LCA(u, v);
        cnt[w]++;
    }
}

void Raze()
{
    cin >> n >> m >> k;
    init_head1(n);
    for (int i = 1; i <= n; i++) vis_node[i] = 0;
    for (int i = 1; i <= m; i++) sel[i] = 0;

    vector<int> may; int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].w %= mod;
        add1_bi(e[i].u, e[i].v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis_node[i]) {
            may.pb(bfs(i));
            tot++;
        }
    }
    if (tot > 2) {
        cout << "0" << endl;
        return;
    }
    if (tot == 2)
    {
        ll ans = 1ll * may[0] * may[1] % mod;
        ans = (ans * k) % mod;
        cout << ans << endl;
        return;
    }
    for (int i = 1; i <= n; i++) vis_node[i] = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 0; j <= 20; j++)
            lca[i][j] = 0;

    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v;
        if (findfa(u) != findfa(v)) mergeuf(u, v), sel[i] = 1;
    }
    build();
    ll ans = 0;
    for (int u = n + 1; u <= now; u++)
    {
        ll res = 1;
        for (int eid = head2[u]; eid != -1; eid = nxt2[eid])
        {
            int v = to2[eid];
            res = res * siz[v] % mod;
        }
        ans = (ans + ( (res - cnt[u] + mod) % mod ) * ( (len[u] - 1 + mod) % mod ) ) % mod;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) Raze();
    return 0;
}
