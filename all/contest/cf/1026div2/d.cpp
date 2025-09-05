#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
int n, m;
int check(int mid, vector<int> &a, vector<vector<PII>> &G)
{
    vector<int> dist(n + 1);
    fill(dist.begin(), dist.end(), -1);
    queue<int> q;
    dist[1] = min(mid, a[1]);
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &t : G[u])
        {
            int v = t.first,w = t.second;
            if (w > mid || dist[u]< w )continue;
            int dis = min(mid, dist[u] + a[v]);
            if (dis > dist[v])
            {
                dist[v] = dis;
                q.push(v);
            }
        }
    }
    return dist[n] >= 0;
}
void solve()
{
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = 0, ans = -1;
    vector<vector<PII>> G(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        r=max(r,w);
        G[u].push_back({v, w});
    }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid, a, G))
        {
            ans = mid,r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (ans < 0)
        cout << "-1\n";
    else
        cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
//si<ti (DAG)