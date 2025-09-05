#include <bits/stdc++.h>
using namespace std;

// 随机数生成器
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// 生成树结构（保证连通）
vector<pair<int, int>> generate_tree(int n) {
    vector<pair<int, int>> edges;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    function<int(int)> find = [&](int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    };

    for (int i = 2; i <= n; i++) {
        int u = rand(1, i - 1);
        edges.emplace_back(u, i);
        parent[find(i)] = find(u);
    }

    // 随机打乱边的顺序
    shuffle(edges.begin(), edges.end(), rng);
    return edges;
}

// 生成测试样例
void generate_test_case(int T) {
    cout << T << endl;
    while (T--) {
        int n = rand(1, 10); // 控制n的范围，方便调试
        int x = rand(2, 20); // 控制x的范围，方便调试

        // 生成树
        auto edges = generate_tree(n);

        // 生成节点值（保证至少有一个节点的值是x的因数）
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            if (rand(0, 1)) a[i] = rand(1, 20); // 随机生成
            else a[i] = x; // 确保至少有一个节点的值是x
        }

        // 输出测试样例（重复两遍）
        for (int repeat = 0; repeat < 2; repeat++) {
            cout << n << " " << x << endl;
            for (auto [u, v] : edges) cout << u << " " << v << endl;
            for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T =  25; // 生成5组测试样例（每组重复两遍）
    generate_test_case(T);

    return 0;
}