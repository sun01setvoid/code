#include <iostream>
using namespace std;
const int N=1010,M=2010;
int visr[N][M],visc[N][M],pre[N][M],mp[N][M];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m;
        int a,b,k,c;
        cin>>n>>m>>k;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++)  
                visr[i][j]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++)  
                visc[i][j]=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>mp[i][j];
                pre[i][j]=pre[i][j-1];
                if (!visr[i][mp[i][j]])  pre[i][j]+=mp[i][j],visr[i][mp[i][j]]=1;
            }
        }
        for (int i=1;i<=m;i++)  visc[i][mp[1][i]]=1;
        for (int i=1;i<=m;i++){
            for (int j=2;j<=n;j++){
                pre[j][i]=pre[j-1][i];
                if (!visc[i][mp[i][j]])  pre[i][j]+=mp[i][j],visr[i][mp[i][j]]=1;
            }
        }
    }
}