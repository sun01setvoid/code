#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector <int> G1[7];
int G2[20][7];
int vis[20];
int res[1<<17];
vector <int> ans;
using namespace std;
void dfs(int u,int st,int s){
    if (u==6) {
        if (!res[s])  ans.push_back(s); 
        res[s]++;
        return;
    }
    for (auto i:G1[u]){
        if (vis[i]!=1){
            for (int j=0;j<=4;j++){
                if (!(st>>j&1) && G2[i][j]){
                    vis[i]=1;
                    dfs(u+1,st|1<<j,s|1<<i);
                    vis[i]=0;
                }
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    int n,q;
    cin>>t;
    while (t--){
        memset(res,0,sizeof res);
        ans.clear();
        cin>>n>>q;
        for (int i=1;i<=5;i++) G1[i].clear();
        for (int i=1;i<=n;i++)
            for (int j=0;j<=4;j++)
                G2[i][j]=0;
        for (int i=1;i<=5;i++){
            int cnti,tmp;
            cin>>cnti;
            for (int j=1;j<=cnti;j++){
                cin>>tmp;
                G1[i].push_back(tmp);
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=0;j<=4;j++) cin>>G2[i][j]; 
        }
        dfs(1,0,0);
        while (q--){
            for (int i=1;i<=n;i++) vis[i]=0;
            int cnti,tmp,j=0;
            cin>>cnti;
            for (int i=1;i<=cnti;i++) cin>>tmp,j|=1<<tmp;
            int sum=0;
            for (auto it:ans){
                if (!(j&it)) sum+=res[it];
            }
            cout<<sum<<"\n";
        }
    }
}
