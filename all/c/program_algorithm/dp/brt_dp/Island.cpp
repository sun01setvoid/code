/*
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1.2e6 + 10;  // 改为1.2e6，与AC代码一致
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//

int n;
int h[maxn], e[maxm], w[maxm], ne[maxm], idx;
int fu[maxn], fw[maxn], q[maxn * 2];  // q需要2倍大小
int cir[maxn], ed[maxn], cnt;
int s[maxn];
bool st[maxn], ins[maxn];
int ans;

// 动态分配，避免栈溢出
vector<int> d, sum;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs_c(int u, int from)
{
    st[u] = ins[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        if (i == (from ^ 1)) continue;
        int j = e[i];
        fu[j] = u, fw[j] = w[i];
        if (!st[j]) dfs_c(j, i);
        else if (ins[j])
        {
            cnt++;
            ed[cnt] = ed[cnt - 1];
            int total = w[i];  // 改名为total避免冲突
            for (int k = u; k != j; k = fu[k])
            {
                s[k] = total;
                total += fw[k];
                cir[++ed[cnt]] = k;
            }
            s[j] = total;
            cir[++ed[cnt]] = j;
        }
    }
    ins[u] = false;
}

int dfs_d(int u)
{
    st[u] = true;
    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j]) continue;
        int dist = dfs_d(j) + w[i];
        if (dist >= d1) d2 = d1, d1 = dist;
        else if (dist > d2) d2 = dist;
    }
    ans = max(ans, d1 + d2);
    return d1;
}

void solve()
{
    cin >> n;
    
    // 正确初始化
    memset(h, -1, sizeof(h));
    idx = 0;
    cnt = 0;
    
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(i, a, b);
        add(a, i, b);
    }
    
    // 找环
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            dfs_c(i, -1);
    }
    
    // 重置标记
    memset(st, 0, sizeof(st));
    for (int i = 1; i <= ed[cnt]; i++)
        st[cir[i]] = true;
    
    // 动态分配数组
    d.resize(2 * n + 10);
    sum.resize(2 * n + 10);
    
    int res = 0;
    for (int i = 1; i <= cnt; i++)
    {
        ans = 0;
        int sz = 0;
        
        // 处理当前环
        for (int j = ed[i - 1] + 1; j <= ed[i]; j++)
        {
            int k = cir[j];
            d[sz] = dfs_d(k);
            sum[sz] = s[k];
            sz++;
        }
        
        // 破环成链
        for (int j = 0; j < sz; j++)
        {
            d[sz + j] = d[j];
            sum[sz + j] = sum[j] + sum[sz - 1];
        }
        
        // 单调队列
        int hh = 0, tt = -1;
        for (int j = 0; j < sz * 2; j++)
        {
            if (hh <= tt && j - q[hh] >= sz) hh++;
            if (hh <= tt) 
                ans = max(ans, d[j] + sum[j] + d[q[hh]] - sum[q[hh]]);
            while (hh <= tt && d[q[tt]] - sum[q[tt]] <= d[j] - sum[j]) tt--;
            q[++tt] = j;
        }
        res += ans;
    }
    cout << res << endl;
}

signed main()
{
    IOS;
    int _ = 1;
    while (_--)
    {
        solve();
    }
    return 0;
}
*/
//基环树直径 https://www.luogu.com.cn/problem/P4381
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define pii pair<int, int>
#define debug(x) cerr << #x << '=' << (x) << endl
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1.2e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//

int n;
vector<vector<pii>> g;        // g[u] = vector of (v, weight) 邻接表
int fu[maxn], fw[maxn], q[maxn*2];         // fu:父节点, fw:到父节点的边权, q:单调队列
int cir[maxn], ed[maxn], cnt;            // cir:环上的节点, ed:每个环的结束位置, cnt:环的数量
int s[maxn], d[maxn * 2], sum[maxn * 2]; // s:环上前缀和, d:子树最大深度, sum:环上距离前缀和
bool st[maxn], ins[maxn];                // st:访问标记, ins:递归栈标记
int ans;                                 // 全局答案

// 找环DFS
// u:当前节点, from:来自哪个节点, fid:来自的边ID(用于跳过反向边)
void dfs_c(int u, int from, int fid)
{
    st[u] = ins[u] = true;
    for (int i = 0; i < g[u].size(); i++)
    {
        auto [j, wgt] = g[u][i];
        int cid = i; // 当前边的ID

        // 跳过反向边(避免走回头路)
        if (cid == fid)
            continue;

        fu[j] = u, fw[j] = wgt; // 记录父节点和边权

        if (!st[j])
            dfs_c(j, u, cid); // 继续DFS
        else if (ins[j])      // 找到环
        {
            cnt++;
            ed[cnt] = ed[cnt - 1]; // 继承上一个环的结束位置
            int sm = wgt; //u->j
            // 回溯记录环上的节点和前缀和
            for (int k = u; k != j; k = fu[k]) //j->u
            {
                s[k] = sm;          // 记录到当前节点的环上前缀和
                sm += fw[k];        // 累加边权
                cir[++ed[cnt]] = k; // 记录环上节点
            }
            s[j] = sm;          // 记录起点j的前缀和 j-u-v2-v3....j(从开始j，到j之前)
            cir[++ed[cnt]] = j; // 记录起点j(遍历方向)，实际这里作为终点
        }
    }
    ins[u] = false; // 回溯，将u移出递归栈
}

// 树形DP求以u为根的子树直径和最大深度
// 返回从u出发的最长路径长度
int dfs_d(int u)
{
    st[u] = true;
    int d1 = 0, d2 = 0; // d1:最长路径, d2:次长路径

    for (auto [j, wgt] : g[u])
    {
        if (st[j])
            continue; // 跳过已访问节点(环上的点)

        int dist = dfs_d(j) + wgt; // 子节点的最大深度 + 边权

        // 更新最长和次长路径
        if (dist >= d1)
            d2 = d1, d1 = dist;
        else if (dist > d2)
            d2 = dist;
    }

    ans = max(ans, d1 + d2); // 更新直径(最长路径+次长路径)
    return d1;               // 返回从u出发的最长路径
}

void solve()
{
    cin >> n;
    g.resize(n + 1);

    // 建图 - 每个岛屿向另一个岛屿建桥，双向边
    for (int i = 1; i <= n; i++)//无向基环树
    {
        int a, b;
        cin >> a >> b;
        // 建立双向边
        g[i].push_back({a, b});
        g[a].push_back({i, b});
    }

    // 找环 - 基环树由多个环组成
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            dfs_c(i, -1, -1);
    }

    // 重置访问标记，用于树形DP
    for (int i = 1; i <= n; i++)
        st[i] = false;

    // 标记环上的点，在树形DP中跳过
    for (int i = 1; i <= ed[cnt]; i++) //ed[cnt]是最后一个点，cir里存点
        st[cir[i]] = true;

    int res = 0; // 最终结果

    // 处理每个环
    for (int i = 1; i <= cnt; i++)
    {
        int ans = 0; // 当前环的最大直径
        int sz = 0;  // 当前环的大小

        // 处理当前环上的每个节点
        for (int j = ed[i - 1] + 1; j <= ed[i]; j++)
        {
            int k = cir[j];
            d[sz] = dfs_d(k); // 树形DP求以k为根的子树最大深度
            sum[sz] = s[k];   // 环上前缀和(从环起点到当前点的距离)
            sz++;
        }
        //0-sz-1

        // 复制数组，处理环的循环性(破环成链)
        for (int j = 0; j < sz; j++)
        {
            d[sz + j] = d[j];
            sum[sz + j] = sum[j] + sum[sz - 1]; // 累加整个环的长度
        }

        // 单调队列求环上最大距离
        // 目标：max(d[i] + d[j] + (sum[i] - sum[j]))，其中i-j <= sz-1
        int hh = 0, tt = -1;
        for (int j = 0; j < sz * 2; j++)
        {
            // 维护队列窗口大小不超过环的大小
            if (hh <= tt && j - q[hh] >= sz)
                hh++;

            // 计算当前最大距离
            if (hh <= tt)
            {
                ans = max(ans, d[j] + sum[j] + d[q[hh]] - sum[q[hh]]);
            }

            // 维护单调递减队列
            while (hh <= tt && d[q[tt]] - sum[q[tt]] <= d[j] - sum[j])
                tt--;
            q[++tt] = j;
        }
        res += ans; // 累加每个环的最大直径
    }
    cout << res << endl;
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