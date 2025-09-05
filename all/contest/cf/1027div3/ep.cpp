#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N], ma[N], mi[N];
vector<int> G[N];

void dfs(int u, int fa) {
    if (fa == -1) {
        ma[u] = a[u];
        mi[u] = a[u];
    } else {
        ma[u] = max(a[u], a[u] - mi[fa]);
        mi[u] = min(a[u], a[u] - ma[fa]);
    }
    for (int v : G[u]) {
        if (v != fa) {
            dfs(v, u);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << ma[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}