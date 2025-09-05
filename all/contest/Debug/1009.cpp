#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+10;
typedef pair<int,int> PII;
int mp[N][N],dist[N][N];
const int INF = 0x3f3f3f3f3f3f3f3f;
int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
int n,m,k;
void bfs(){
    memset(dist,0x3f,sizeof dist);
    deque <PII> q;
    for (int i=2;i<=m;i++){
        if (mp[1][i]==0) dist[1][i]=1,q.push_back({1,i});
        else dist[1][i]=0,q.push_front({1,i});
    }
    for (int i=2;i<=n-1;i++){
        if (mp[i][m]==0) dist[i][m]=1,q.push_back({i,m});
        else dist[i][m]=0,q.push_front({i,m});
    }
    while (q.size()){
        auto t=q.front();
        q.pop_front();
        int x=t.first,y=t.second;
        for (int i=0;i<8;i++){
            int nx=x+dir[i][0],ny=y+dir[i][1];
            if (nx<1||nx>n||ny<1||ny>m || (nx==1 && ny==1) || (nx==n && ny==m)) continue;
            if (mp[nx][ny]==1){
                if (dist[nx][ny]>dist[x][y]) {
                    dist[nx][ny]=dist[x][y];
                    q.push_front({nx,ny});
                }
            } else if (mp[nx][ny]==0){
                if (dist[nx][ny]>dist[x][y]+1) {
                    dist[nx][ny]=dist[x][y]+1;
                    q.push_back({nx,ny});
                }
            }
        }
    }
    return;
}
signed main(){
    int T;
    cin>>T;
    while (T--){
        cin>>n>>m>>k;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                mp[i][j]=0;
        while (k--){
            int x,y;
            cin>>x>>y;
            mp[x][y]=1;
        }
        bfs();
        int ans=INF;
        for (int i=2;i<=n;i++){
            ans=min(ans,dist[i][1]);
        }
        for (int i=1;i<=m-1;i++){
            ans=min(ans,dist[n][i]);
        }
        cout<<ans<<endl;
    }
}