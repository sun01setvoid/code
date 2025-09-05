#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAXN = 2e5 + 5;
vector<int> G[MAXN];
LL ans[MAXN];
int sz[MAXN];
int n;

void dfs(int u, int fa) {
    sz[u] = 1;
    for (int v : G[u]) {
        if (v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
            ans[u] += 1LL * sz[v] * (n - sz[v]);
        }
    }
    ans[u] += 1LL * sz[u] * (n - sz[u]);
    ans[u] += n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            ans[i] = 0;
            sz[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, 0);
        cout<<ans[1];
        for (int i = 2; i <= n; ++i) {
            cout <<" "<< ans[i];
        }
        cout<<endl;
    }
    return 0;
}