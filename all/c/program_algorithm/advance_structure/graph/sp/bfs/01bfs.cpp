//acw 175
#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
typedef pair <int,int> PII;
const int N=510;
string mp[N];
int dist[N][N];
int n,m;
void bfs(){
    memset(dist,0x3f,sizeof dist);
    char gh[]="\\\\//";//转义字符
    int dx[]={-1,1,-1,1},dy[]={-1,1,1,-1};//一个点移动
    int tx[]={-1,0,-1,0},ty[]={-1,0,0,-1};//一个边移动，转换一下
    deque <PII> q;
    dist[1][1]=0;
    q.push_back({1,1});
    while (q.size()){
        auto t=q.front();
        q.pop_front();
        int x=t.first,y=t.second;
        if (x==n+1 && y==m+1)   break;
        for (int i=0;i<4;i++){
            int xi=x+dx[i],yi=y+dy[i];
            int xj=x+tx[i],yj=y+ty[i];
            if (xi>n+1 || xi<1 || yi>m+1 || yi<1)   continue;
            if (mp[xj][yj]==gh[i] && dist[xi][yi]>dist[x][y])   dist[xi][yi]=dist[x][y],q.push_front({xi,yi});  
            else if (mp[xj][yj]!=gh[i] && dist[xi][yi]>dist[x][y]+1)    dist[xi][yi]=dist[x][y]+1,q.push_back({xi,yi});
        }
    }
    return;
}
int main(){
    int T;
    string tmp;
    cin>>T;
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=n;i++)
            cin>>tmp,mp[i]="#"+tmp;
        bfs();
        if (dist[n+1][m+1]==0x3f3f3f3f) {puts("NO SOLUTION");continue;}
        cout<<dist[n+1][m+1]<<endl;
    }
    return 0;
}