//practice
#include <iostream>
using namespace std;
typedef long long LL;
const int N=50010,M=210,MOD=1e9+7;
int f[N][M],C[M][M];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    f[0][0]=1;
    for (int i=1;i<N;i++)
        for (int j=1;j<M;j++)  
        f[i][j]=(f[i-1][j-1]+(LL)(i-1)*f[i-1][j])%MOD;
    for (int i=0;i<M;i++){
        for (int j=0;j<=i;j++){
            if (!j) C[i][j]=1;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
    int T;
    cin>>T;
    while (T--){
        int n,a,b;
        cin>>n>>a>>b;
        cout<<(LL)f[n-1][a+b-2]*C[a+b-2][a-1]%MOD<<endl;
    }
}