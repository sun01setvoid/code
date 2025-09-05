#include <iostream>
#include <queue>
using namespace std;
const int N=510;
struct node{
    int x;
    int y;
};
typedef pair <node,int> PII;
int mp[N][N];
int vis[N][N];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    int ri;
    int tmp;
    while (t--){
        cin>>n>>m;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                mp[i][j]=0,vis[i][j]=0;
        for (int i=1;i<=n;i++){
            cin>>ri;
            for (int j=1;j<=ri;j++){
                cin>>tmp;
                mp[i][tmp]=1;
            }
        }
        int ans=0x3f3f3f3f;
        queue <PII> q;
        for (int i=1;i<=n;i++){
            if (!mp[i][1])
            q.push({{i,1},1});
        }
        while (q.size()){
            auto it=q.front();
            q.pop();
            int x=it.first.x,y=it.first.y;
            int dis=it.second;
            if (y==m){
                ans=min(ans,dis);
            }
            for (int i=0;i<4;i++){
                int xi=x+dir[i][0],yi=y+dir[i][1];
                if (xi<1 || xi>n || yi<1 || yi>m)   continue;
                if (!vis[xi][yi] && !mp[xi][yi]) vis[xi][yi]=1,q.push({{xi,yi},dis+1});
            }
        }
        cout<<ans<<"\n";
    }
}