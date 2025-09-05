//https://acm.hdu.edu.cn/contest/problems?cid=1173
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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{
    int to, nex;
}e[maxn << 1];
int head[maxn << 1], cnt; int n, m, r;
int w[maxn], wnew[maxn], id2[maxn], tot;
int dep[maxn], siz[maxn], son[maxn], top[maxn], fa[maxn], id[maxn]; int num;
int ls(int x) { return x << 1; }int rs(int x) { return x << 1 | 1; }
int tree[maxn << 2], lazy[maxn << 2], tag[maxn];
void init()
{
    for (int i = 0; i <=n*2; i++) { e[i].nex = -1; head[i] = -1; }
    cnt = 0; tot = 0; num = 0;
    for (int i = 1; i <= n; i++)tag[i] = 0, son[i] = 0;
}
void add(int u, int v)
{
    e[cnt].to = v; e[cnt].nex = head[u]; head[u] = cnt++;
}
void pushup(int node) { tree[node] = max(tree[ls(node)], tree[rs(node)]); }
void addlazy(int node, int l, int r, int val)
{
    lazy[node] += val; tree[node] += val;
}
void pushdown(int node, int l, int r)
{
    if (lazy[node])
    {
        int mid = (l + r) >> 1;
        addlazy(ls(node), l, mid, lazy[node]);
        addlazy(rs(node), mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }
}
void build(int node, int l, int r)
{
    lazy[node] = 0; if (l == r) { tree[node] = wnew[l]; return; }
    int mid = (l + r) >> 1; build(ls(node), l, mid); build(rs(node), mid + 1, r); pushup(node);
}
void update(int node, int l, int r, int ql, int qr, int val)
{
    if (l >= ql && r <= qr) { addlazy(node, l, r, val); return; }
    pushdown(node, l, r); int mid = (l + r) >> 1;
    if (mid >= ql)update(ls(node), l, mid, ql, qr, val);
    if (mid < qr)update(rs(node), mid + 1, r, ql, qr, val);
    pushup(node);
}
int query(int node, int l, int r, int ql, int qr)
{
    if (l >= ql && r <= qr) { return tree[node]; }
    pushdown(node, l, r); int mid = (l + r) >> 1; int ans = 0;
    if (mid >= ql)ans = max(ans,query(ls(node), l, mid, ql, qr));
    if (mid < qr)ans =max(ans, query(rs(node), mid + 1, r, ql, qr));
    return ans;
}
void dfs1(int u, int pa)
{
    dep[u] = dep[pa] + 1; fa[u] = pa; siz[u] = 1;
    for (int i = head[u]; ~i; i = e[i].nex)
    {
        int v = e[i].to;
        if (v != pa)
        {
            fa[v] = u; dfs1(v, u);
            siz[u] += siz[v];
            if (!son[u] || siz[v] > siz[son[u]])son[u] = v;
        }
    }
}
void dfs2(int x, int topx)
{
    id[x] = ++num; wnew[num] = w[x];
    top[x] = topx; if (!son[x])return;
    dfs2(son[x], topx);
    for (int i = head[x]; ~i; i = e[i].nex)
    {
        int y = e[i].to; if (y != fa[x] && y != son[x])dfs2(y, y);//每个轻儿子都有从他自己开始的链
    }
}
void uprange(int x, int y, int z)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])swap(x, y);
        update(1, 1, n, id[top[x]], id[x], z); x = fa[top[x]];
    }
    if (dep[x] > dep[y])swap(x, y); update(1, 1, n, id[x], id[y], z);
}
int qrange(int x, int y)
{
    int ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])swap(x, y);
        ans = max(ans,query(1, 1, n, id[top[x]], id[x]));
        ans = max(ans, wnew[id[top[x]]] + tag[id[fa[top[x]]]]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])swap(x, y); ans = max(ans, query(1, 1, n, id[x], id[y]));
    if (x == top[x])ans = max(ans, query(1, 1, n, id[x], id[x]) + tag[id[fa[x]]]);
    if (y == top[y])ans = max(ans, query(1, 1, n, id[y], id[y]) + tag[id[fa[y]]]);
    return ans;
}
void upd(int x, int val)
{
    if (fa[x] != 0)update(1, 1, n, id[fa[x]], id[fa[x]], val);
    if(son[x]!=0)update(1, 1, n, id[son[x]], id[son[x]], val);
    tag[id[x]] += val;
}
void Raze()
{
    cin >> n >> m; init();
    for (int i = 1; i <= n; i++)cin >> w[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        add(u, v); add(v, u);
    }
    dfs1(1, 0);dfs2(1, 1); build(1, 1, n);
    for (int i = 1; i <= n; i++)cout << son[i] << " "; cout << endl;
    while (m--)
    {
        int op, x, y; cin >> op >> x >> y;
        if (op == 1)
        {
            cout << qrange(x, y) << endl;
        }
        else
        {
            upd(x, y);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}