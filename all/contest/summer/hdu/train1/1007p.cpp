#include <bits/stdc++.h>
using namespace std;
const int M = 1e7 + 5;
int n, x;
bool vis[M];
int mu[M];
int prime[M], nowp;
const int N = 1e5 + 5;
int to[2 * N], ed[2 * N], nxt[2 * N], now;
int a[N];
void sieve()
{
    mu[1] = 1;
    for (int j = 2; j < M; j++)
    {
        if (!vis[j])
        {
            prime[++nowp] = j;
            mu[j] = -1;
        }
        for (int i = 1; i <= nowp; i++)
        {
            int p = prime[i];
            if (1ll * p * j < M)
            {
                vis[p * j] = 1;
                if (j % p == 0)
                {
                    mu[p * j] = 0;
                    break;
                }
                else
                    mu[p * j] = -mu[j];
            }
            else
                break;
        }
    }
    return;
}
void addEdge(int u, int v)
{
    now++;
    to[now] = v;
    nxt[now] = ed[u];
    ed[u] = now;
}
int res;
int cnt[N];
void dfs(int u, int fa, int d)
{
    if (d % a[u] == 0)
        cnt[u] = 1, res++;
    else
        cnt[u] = 0;
    for (int i = ed[u]; i != -1; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        dfs(v, u, d);
        if (d % a[u] == 0)
        {
            res += 1ll * cnt[u] * cnt[v];
            cnt[u] += cnt[v];
        }
    }
    return;
}
int solve()
{
    cin >> n >> x;
    now = 0;
    for (int i = 1; i <= n; i++)
        ed[i] = -1;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i != 0)
            continue;
        if (mu[x / i] != 0) // 256
        {
            res = 0;
            dfs(1, 0, i); // 3e5
            ans += res * mu[x / i];
        }
        if (i != x / i)
        {
            if (mu[i] != 0)
            {
                res = 0;
                dfs(1, 0, x / i);
                ans += res * mu[i];
            }
        }
    }
    cout << ans << "\n";
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
/*


*/