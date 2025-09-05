        #include <iostream>
#include <vector>
using namespace std;
vector <int> G1[7];
int G2[20][7];
int vis[20],ans;
using namespace std;
void dfs(int u,int st){
    if (u==6) {++ans;return;}
    for (auto i:G1[u]){
        if (vis[i]!=1){
            for (int j=0;j<=4;j++){
                if (!(st>>j&1) && G2[i][j]){
                    vis[i]=1;
                    dfs(u+1,st|1<<j);
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
        while (q--){
            for (int i=1;i<=n;i++) vis[i]=0;
            int cnti,tmp;
            cin>>cnti;
            for (int i=1;i<=cnti;i++) cin>>tmp,vis[tmp]=1;
            ans=0;
            dfs(1,0);
            cout<<ans<<"\n";
        }
    }
}
