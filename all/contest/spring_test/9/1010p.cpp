#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
int degree[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; ++i) {
            adj[i].clear();
            degree[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        bool possible = true;
        vector<int> current_degree(degree, degree + n + 1);

        for (int i = n; i >= 1; --i) {
            int cnt = 0;
            for (int j : adj[i]) {
                if (j < i && j != 0) {
                    cnt++;
                    if (--current_degree[j] == 0) {
                        possible = false;
                    }
                }
            }
            if (current_degree[i] - cnt != 0) {
                possible = false;
            }
            current_degree[i] -= cnt;

            if (!possible) break;
        }

        cout << (possible ? 1 : 0) << '\n';
    }

    return 0;
}