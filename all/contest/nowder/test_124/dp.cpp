
#include <bits/stdc++.h>
 
using i64 = long long;
 
struct DSU {
    std::vector<int> f, sz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    int size(int x) {
        return sz[find(x)];
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
     
    int n;
    std::cin >> n;
 
    std::vector<int> w(n);
    for (auto &x: w) {
        std::cin >> x;
    }
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[w[i]].push_back(i);
    }
 
    i64 ans = 0;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ans += (w[u] == w[v]) * 2;
    }
 
    DSU dsu(n);
    std::vector<int> cnt(n);
    std::vector<int> node;
    node.reserve(n);
    for (const auto &[val, p]: pos ) {
        node.clear();
        for (int x: p) {
            for (int y: adj[x]) {
                if (w[y] <= w[x]) {
                    continue;
                }
                int f = dsu.find(y);
                if (cnt[f]++ == 0) {
                    node.push_back(f);
                }
            }
        }
        for (int x: node) {
            ans += cnt[x] * (cnt[x] - 1LL);
            cnt[x] = 0;
        }
        for (int x: p) {
            for (int y: adj[x]) {
                if (w[y] >= w[x]) {
                    dsu.merge(x, y);
                }
            }
        }
    }
    std::cout << ans << "\n";
     
    return 0;
}