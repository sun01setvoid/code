#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int H, W;
vector<vector<LL>> mp;
vector<vector<bool>> vis;
LL ans = 0;
void dfs(int i, int j, LL res) {
    if (i == H) {
        ans = max(ans, res);
        return;
    }
    if (j == W) {
        dfs(i + 1, 0, res);
        return;
    }
    if (vis[i][j]) {
        dfs(i, j + 1, res);
        return;
    }

    dfs(i, j + 1, res ^ mp[i][j]);
    if (j + 1 < W && !vis[i][j + 1]) {
        vis[i][j] = vis[i][j + 1] = true;
        dfs(i, j + 2, res);
        vis[i][j] = vis[i][j + 1] = false;
    }
    if (i + 1 < H && !vis[i + 1][j]) {
        vis[i][j] = vis[i + 1][j] = true;
        dfs(i, j + 1, res);
        vis[i][j] = vis[i + 1][j] = false;
    }
}

int main() {
    cin >> H >> W;
    mp.resize(H, vector<LL>(W));
    vis.resize(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> mp[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}