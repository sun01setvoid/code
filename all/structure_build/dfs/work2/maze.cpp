#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
const int N=25;
int mp[N][N],vis[N][N];//地图和标记
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int n,m;//长、宽
int stx,sty,enx,eny;
vector <PII> path;

bool dfs(int x,int y,int dis){
    vis[x][y]=1;
    path.push_back({x,y});
    if (x==enx && y==eny)   {
        return true;
    }
    for (int i=0;i<4;i++){
        int xi=x+dir[i][0],yi=y+dir[i][1];
        if (xi<1 || xi>n || yi<1 || yi>m)   continue;
        if (!vis[xi][yi] && !mp[xi][yi]) {  //没被走过且是通道
            if(dfs(xi,yi,dis+1))
            return true;
        }
    }
    //剪枝
    //因为递归会走尽可以走的路，所以不用回溯标记
    //因为该点之后走的路到不了终点，不管从哪里再到该点上也到不了终点
    path.pop_back();//走不到的退回
    return false;
}

int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>mp[i][j];
    cin>>stx>>sty>>enx>>eny;//起始和终止位置
    if (dfs(stx,sty,0)){
        for (auto i:path){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
    else puts("No Solution!");
}

/*test*/
/*
5 5
0 0 0 1 0
0 1 0 0 0
0 0 1 1 1
1 0 0 0 0
1 1 0 0 1
1 1
4 5
*/

//DFS适合任意可行解，BFS适合全局最优解