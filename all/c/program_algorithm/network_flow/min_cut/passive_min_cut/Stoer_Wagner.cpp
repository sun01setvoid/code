#include <cstring>
#include <iostream>
using namespace std;
constexpr int N = 601;
constexpr int inf = 0x3f3f3f3f;
int fa[N], siz[N], edge[N][N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int dist[N], vis[N], bin[N]; // bin标记有没有使用过
int n, m;
int contract(int &s, int &t) // 这是O(V*V*V+N*M) //可以用堆优化，找最小值，但没什么必要
{                            // Find s,t
    for (int i = 1; i <= n; i++)
        dist[i] = 0;
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    int i, j, k, mincut, maxc;
    for (i = 1; i <= n; i++)
    {
        k = -1;
        maxc = -1;
        for (j = 1; j <= n; j++)
            if (!bin[j] && !vis[j] && dist[j] > maxc)
            {
                k = j;
                maxc = dist[j];
            }
        if (k == -1)
            return mincut;
        s = t;
        t = k;
        mincut = maxc;
        vis[k] = true;
        for (j = 1; j <= n; j++)
            if (!bin[j] && !vis[j])
                dist[j] += edge[k][j]; // 记录每个顶点到当前集合 A 的连通度（边权和）。每次取最大的
    }
    return mincut;
}
int Stoer_Wagner()
{
    int mincut, i, j, s, t, ans;
    for (mincut = inf, i = 1; i < n; i++)
    {
        ans = contract(s, t);//找s-t最小割
        //cout << s << " " << t << endl;
        bin[t] = true;
        if (mincut > ans)
            mincut = ans;
        if (mincut == 0)
            return 0;
        for (j = 1; j <= n; j++)
            if (!bin[j])
                edge[s][j] = (edge[j][s] += edge[j][t]); // 连通块缩成一个点
    }
    return mincut;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    if (m < n - 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        fa[i] = i, siz[i] = 1;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        int fu = find(u), fv = find(v);
        if (fu != fv)
        {
            if (siz[fu] > siz[fv])
                swap(fu, fv);
            fa[fu] = fv, siz[fv] += siz[fu];
        }
        edge[u][v] += w, edge[v][u] += w;
    }
    int fr = find(1);
    if (siz[fr] != n)
    {
        cout << 0;
        return 0;
    }
    cout << Stoer_Wagner();
    return 0;
}