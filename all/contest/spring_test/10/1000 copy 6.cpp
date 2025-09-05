#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10, M = 5e6 + 10;
typedef pair<int, int> PII;
int h[N], e[M], w[M], ne[M], idx;
int st[N], dist[N];
int n, m, x;
const int INF = 0x3f3f3f3f3f3f3f3f;
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra() {
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[3] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 3});
    while (!heap.empty()) {
        auto [d, u] = heap.top();
        heap.pop();
        if (st[u]) continue;
        st[u] = 1;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                heap.push({dist[v], v});
            }
        }
    }
    return dist[3 * n] == INF ? -1 : dist[3 * n];
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> x;
        idx = 0;
        memset(h,-1,sizeof h);
        map<int, vector<int>> G;
        for (int i = 1; i <= n; i++){
            int tmp;
            cin >> tmp;
            G[tmp].push_back(i);
        }
        for (int i=1;i<=n;i++) {
            if (G[i].size())
            for (int j:G[i]) {
                add(3 * j, 3 * (i + n) + 1, x);
                add(3 * j + 1, 3 * (i + n) + 2, x);
                add(3 * j + 2, 3 * (i + n), x);
                add(3 * (i + n), 3 * j, 0);
                add(3 * (i + n) + 1, 3 * j + 1, 0);
                add(3 * (i + n) + 2, 3 * j + 2, 0);
            }
        }
        while (m--) {
            int u, v, c;
            cin >> u >> v >> c;
            add(3 * u, 3 * v + 1, c);
            add(3 * u + 1, 3 * v + 2, c);
            add(3 * u + 2, 3 * v, c);
        }
        cout << dijkstra() << '\n';
    }
}
