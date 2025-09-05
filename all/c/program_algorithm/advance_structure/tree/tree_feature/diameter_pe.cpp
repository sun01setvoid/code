// 可以得到沿途路径和路径长度
// 如果需要求出一条直径上所有的节点，
// 则可以在第二次 DFS 的过程中，记录每个点的前序节点，
// 即可从直径的一端一路向前，遍历直径上所有的节点。

// lgP3304,会爆栈
#include <iostream>
#include <cstring>
using namespace std;
#define int long long 
const int N = 2e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], last[N], diam[N];
int n;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs1(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        dist[j] = dist[u] + w[i];
        dfs1(j, u);
    }
}
void dfs2(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        last[j] = u;
        dist[j] = dist[u] + w[i];
        dfs2(j, u);
    }
}
int dfs3(int u, int fa, int dis)
{
    int ans = dis;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa || diam[j])
            continue;
        ans = max(ans, dfs3(j, u, dis + w[i]));
    }
    return ans;
}
signed main()
{
    memset(h, -1, sizeof h);
    idx=0;
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dist[1] = 0;
    dfs1(1, -1);
    int st = 1, en = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > dist[st])
        {
            st = i;
        }
    }
    dist[st] = 0;
    dfs2(st, -1);
    last[st] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > dist[en])
        {
            en = i;
        }
    }
    cout << dist[en] << endl;
    for (int i = en; i != -1; i = last[i])
        diam[i] = 1;
    int l = st, r = en;
    for (int i = en; i != st; i = last[i])
    {
        int maxdist = dfs3(i, -1, 0);
        //cout<<i<<" "<<maxdist<<endl;
        if (maxdist == dist[en] - dist[i])
            r = i;
        if (maxdist == dist[i] && l == st)  //r不可能在l左边，因为这样他就不是直径了
            l = i;
    }
    int len = 0;
    for (int i = r; i != l; i = last[i])
        len++;
    cout << len << endl;
}