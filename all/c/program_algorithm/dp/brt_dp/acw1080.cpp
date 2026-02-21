/*
// 基环内向树是每个点只有一条出度
// 基环外向树是每个点只有一条入度
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n;
bool st[maxn], ins[maxn], rm[maxn];
int f1[maxn][2], f2[maxn][2]; // 两次dp
int ans;
// 基环树拆环做dp
//有环的dfs,最好不要用树的遍历方式，因为会有多重边，最好用边的 i==(from^1) continue
void dfs_f(int u, int ap, int f[][2]) // ap表示哪个点不能选
{
    f[u][1] = w[u];
    if (u == ap)
        f[u][1] = -INF;
    for (int i = h[u]; ~i; i = ne[i])
    {
        if (rm[i])
            continue;
        int j = e[i];
        dfs_f(j, ap, f);
        f[u][0] += max(f[j][1], f[j][0]);
        if (u != ap)
        {
            f[u][1] += f[j][0];
        }
    }
}
void dfs_c(int u)
{
    st[u] = ins[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
            dfs_c(j);
        else if (ins[j])
        {
            rm[i] = 1; // 删边
            dfs_f(j, -1, f1);
            dfs_f(j, u, f2);
            ans += max(f1[j][0], f2[j][1]);//因为可能有多棵基环树
        }
    }
    ins[u] = 0;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        h[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        w[i] = a;
        add(b, i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            dfs_c(i);
    }
    cout << ans << endl;
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
*/
// 基环内向树是每个点只有一条出度
// 基环外向树是每个点只有一条入度
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define pb push_back
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//

vector<vector<pii>> g(maxn); // g[u] = vector of (v, eid) 邻接表存储图
int n;
bool st[maxn], ins[maxn], rm[maxn]; // st:访问标记, ins:递归栈标记, rm:边删除标记
int f1[maxn][2], f2[maxn][2]; // f1/f2:两次DP的结果，f[u][0]不选u, f[u][1]选u
int ans; // 最终答案
int w[maxn]; // 每个骑士的战斗力

// 树形DP计算最大独立集

// u:当前节点, ap:禁止选择的节点, f:DP数组
void dfs_f(int u, int ap, int f[][2])
{
    f[u][1] = w[u];
    if (u == ap)    // 如果u是禁止选择的节点
        f[u][1] = -inf; // 将选择u的收益设为负无穷，强制不选
    
    for (auto &[j, eid] : g[u]) // 遍历u的所有子节点
    {
        if (rm[eid]) // 如果这条边被删除了，跳过
            continue;
        dfs_f(j, ap, f); // 递归处理子节点
        
        // 不选u时，子节点可选可不选
        f[u][0] += max(f[j][1], f[j][0]);
        
        //禁止节点不能选
        if (u != ap)
        {
            f[u][1] += f[j][0];
        }
    }
}

// 找环并处理基环树
void dfs_c(int u)
{
    st[u] = ins[u] = 1;
    
    for (auto &[j, eid] : g[u])
    {
        if (!st[j]) 
            dfs_c(j);
        else if (ins[j]) // 邻接点在递归栈中，说明找到了环
        {
            rm[eid] = 1; // 删除这条边，将基环树变为树
            // 第一次DP：j节点可以自由选择（ap=-1）
            dfs_f(j, -1, f1);
            // 第二次DP：强制不选u（即环上的相邻点）
            dfs_f(j, u, f2);
            // 累加这棵基环树的最大值：
            // f1[j][0]: 不选j的情况
            // f2[j][1]: 选j但强制不选u的情况
            ans += max(f1[j][0], f2[j][1]);
        }
    }
    ins[u] = 0; // 回溯，将u移出递归栈
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    
    int eid = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        w[i] = a; 
        g[b].push_back({i, eid++});
    }
    
    // 遍历所有连通分量（可能有多棵基环树）
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            dfs_c(i);
    }
    cout << ans << endl;
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