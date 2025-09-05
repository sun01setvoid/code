// P4716 最小树形图（有向边）
// O(n**3) O(n*m)（只求值）
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
const int maxn = 110;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, rt;
int d[maxn][maxn], bd[maxn][maxn];
int pre[maxn];
int dfn[maxn], low[maxn], ts, stk[maxn], top;
int id[maxn], cnt;
bool st[maxn], ins[maxn];
void dfs(int u) // 判断能不能走到
{
    st[u] = true;
    for (int i = 1; i <= n; i++)
        if (d[u][i] != inf && !st[i])
            dfs(i);
}
bool check()
{
    memset(st, 0, sizeof st);
    dfs(rt);
    for (int i = 1; i <= n; i++)
        if (!st[i])
            return false;
    return true;
}

void tarjan(int u) // 求环
{
    dfn[u] = low[u] = ++ts;
    stk[++top] = u, ins[u] = true;
    int j = pre[u];
    if (!dfn[j])
    {
        tarjan(j);
        low[u] = min(low[u], low[j]);
    }
    else if (ins[j])
        low[u] = min(low[u], dfn[j]);

    if (low[u] == dfn[u])
    {
        int y;
        ++cnt;
        do
        {
            y = stk[top--], ins[y] = false, id[y] = cnt;
        } while (y != u);
    }
}

int work()
{
    int res = 0;
    while (true)
    {
        for (int i = 1; i <= n; i++)
        {
            pre[i] = i;
            for (int j = 1; j <= n; j++) // 找最小前向边
                if (d[pre[i]][i] > d[j][i])
                    pre[i] = j;
        }
        memset(dfn, 0, sizeof dfn);
        ts = cnt = 0;
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
        if (cnt == n) // 没有环
        {
            for (int i = 1; i <= n; i++)
            {
                if (i != rt)
                    res += d[pre[i]][i];
            }
            break;
        }

        for (int i = 1; i <= n; i++)
        {
            if (i != rt && id[pre[i]] == id[i])
                res += d[pre[i]][i];
        }

        for (int i = 1; i <= cnt; i++)
            for (int j = 1; j <= cnt; j++) // 新图
                bd[i][j] = inf;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)             // 新图
                if (d[i][j] < inf && id[i] != id[j]) // 环的都不管,所以根的自环也不管
                {
                    int a = id[i], b = id[j];
                    if (id[pre[j]] == id[j])
                        bd[a][b] = min(bd[a][b], d[i][j] - d[pre[j]][j]);
                    else
                        bd[a][b] = min(bd[a][b], d[i][j]);
                }

        n = cnt;
        rt = id[rt];//注意G'的rt
        memcpy(d, bd, sizeof d);
    }

    return res;
}
signed main()
{
    cin >> n >> m >> rt;
    memset(d, 0x3f, sizeof d);
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        if (a != b && b != rt) // 注意不要自环和指向根的
            d[a][b] = min(d[a][b], w);//注意
    }

    if (!check())
        cout << -1 << endl;
    else
        cout << work() << endl;

    return 0;
}