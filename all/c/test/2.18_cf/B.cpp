#include <iostream>
#include <algorithm>
using namespace std;
int mp[500010];
int a[800][800];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int vis[800][800];
int sum;
int n,m;
void dfs(int x,int y){
    vis[x][y]=1;
    sum++;
    for (int i=0;i<4;i++){
        int xi=dir[i][0]+x,yi=dir[i][1]+y;
        if (xi<1 || xi>n || yi<1 || yi>m){
            continue;
        }
        if (!vis[xi][yi] && a[xi][yi]==a[x][y])
            dfs(xi,yi);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>n>>m;
        int ma=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        for (int i=1;i<=n*m;i++)    mp[i]=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (!vis[i][j]){
                    sum=0;
                    dfs(i,j);
                    if (sum>1) mp[a[i][j]]=2;
                    else mp[a[i][j]]=max(mp[a[i][j]],1);
                    if (mp[a[i][j]]>mp[ma]) ma=a[i][j];
                }
            }
        }
        int cnt=0;
        for (int i=1;i<=n*m;i++){
            if (mp[i] && i!=ma) cnt+=mp[i];
        }
        cout<<cnt<<endl;
    }
}