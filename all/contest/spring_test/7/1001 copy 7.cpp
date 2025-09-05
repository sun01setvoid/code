#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int N = 1e5 + 10;
LL dp[N];
int f[N];
int h[N], ne[2 * N], idx, e[2 * N];
LL w[2 * N], rw[2 * N], dist[N], rdist[N];
void add(int a, int b, LL c, LL d)
{
    rw[idx] = d, w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx, idx++;
}
void dfs(int x, int fa)
{
    f[x] = fa;
    for (int i = h[x]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        dist[j] = dist[x] + w[i];
        rdist[j] = rdist[x] + rw[i];
        dfs(j, x);
        dp[x] = max(dp[x], dp[x] + w[i] + rw[i] + dp[j]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    int n, u, v;
    int s, t;
    LL p, q;
    while (T--)
    {
        cin >> n;
        idx = 0;
        for (int i = 1; i <= n; i++)
            dp[i] = 0, h[i] = -1,dist[i]=rdist[i]=0;
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> u >> v >> p >> q;
            add(u, v, p, q);
            add(v, u, q, p);
        }
        cin >> s >> t;
        dfs(s, 0);
        LL ans = 0;
        ans = dist[t];
        for (int sn1 = t, now = f[t]; now != 0; now = f[now])
        {
            if (dp[now] > 0)
            {
                if (dp[sn1] + rdist[sn1] - rdist[now] + dist[sn1] - dist[now] > 0)
                    ans += dp[now] - (dp[sn1] + rdist[sn1] - rdist[now] + dist[sn1] - dist[now]);
                else
                    ans+=dp[now];
            }
            sn1=now;
        }
        cout << ans << "\n";
    }
}