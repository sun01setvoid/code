#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // 用于sort函数

using namespace std;

typedef pair<int,int> PII;
const int N=10;
int vis[N][N];//地图和标记
int dir[8][2]={-2,-1,-2,1,-1,2,1,2,2,-1,2,1,-1,-2,1,-2};
int n,m;//长、宽
vector <PII> path;

// 计算当前位置的可达方向数（出度）
int getOutDegree(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 1 && nx <= n && ny >=1 && ny <= m && !vis[nx][ny])
            cnt++;
    }
    return cnt;
}

bool dfs(int x,int y,int cnt){
    vis[x][y] = 1;
    path.push_back({x,y});
    
    if (cnt == n*m) return true;
    
    vector<PII> nextSteps;
    for (int i = 0; i < 8; i++) {
        int xi = x + dir[i][0], yi = y + dir[i][1];
        if (xi >= 1 && xi <= n && yi >= 1 && yi <= m && !vis[xi][yi]) {
            nextSteps.emplace_back(xi, yi);
        }
    }
    
    // 按出度从小到大排序（Warnsdorff规则）
    sort(nextSteps.begin(), nextSteps.end(), [&](const PII& a, const PII& b) {
        return getOutDegree(a.first, a.second) < getOutDegree(b.first, b.second);
    });
    
    for (auto &p : nextSteps) {
        if (dfs(p.first, p.second, cnt + 1)) {
            return true;
        }
    }
    
    // 回溯
    vis[x][y] = 0;
    path.pop_back();
    return false;
}

int main(){
    cin>>n>>m;
    bool found = false;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            memset(vis, 0, sizeof vis);
            path.clear();
            if (dfs(i,j,1)){
                cout<<i<<" "<<j<<endl;
                found = true;
                // 如果只需要找到第一个可行解，可以在这里break
                // break;
            }
        }
        // if (found) break;
    }
    if (!found) 
        puts("No Solution!");
    
    return 0;
}
/*test*/
/*
8 8
1 1
*/