//适用于(固定关系下一维(答案数量）k阶（多少阶段）和k维一阶)
//（k维1阶a[i][1]=a[i-1][2]+a[i-1][1]+2*a[i-1][3])
//lg p1962,数学归纳法推导矩阵（1维k阶），k是方阵大小，1维k阶行向量*方阵
//k维，k维1阶列向量*方阵
//O(N*N*N*logn)
//dp[i][j][k] j,k>=0 && j,k<=2,三进制转十进制，转换为成二维
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=5,mod=1e9+7;
struct matrix{LL m[N][N];int rk,col;};
matrix operator * (const matrix &a,const matrix&b){
    matrix c;
    memset(c.m,0,sizeof(c.m));
    for (int i=1;i<=a.rk;i++){
        for (int j=1;j<=b.col;j++){
            for (int k=1;k<=a.col;k++)
                //c.m[i][j]=a.m[i][k]*b.m[k][j];
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
        }
    }
    c.rk=a.rk,c.col=b.col;
    return c;
}
matrix qpower(matrix a,LL n){
    matrix ans;
    memset(ans.m,0,sizeof (ans.m));
    for (int i=1;i<=a.rk;i++)  ans.m[i][i]=1;//必须是方阵
    ans.rk=a.rk,ans.col=a.col;
    while (n){
        if (n&1)    ans=ans*a;
        a=a*a;
        n>>=1;
    }
    return ans;
}
int main(){
    LL n;
    cin>>n;
    matrix m1,a,tmp;
    m1.m[1][1]=1,m1.m[1][2]=1,m1.rk=1,m1.col=2;
    a.m[1][1]=1,a.m[1][2]=1,a.m[2][1]=1,a.m[2][2]=0,a.rk=2,a.col=2;
    if (n<=2)   cout<<m1.m[1][3-n];
    else{
        tmp=qpower(a,n-2);
        tmp=m1*tmp;
        cout<<tmp.m[1][1];
    }
}