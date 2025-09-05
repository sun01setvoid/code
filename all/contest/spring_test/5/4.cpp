//k次幂可快速幂
//就是两两相乘啦
//空集记0位置上为1
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD= 998244353,N=210;
LL arr[210],n;
int m;
struct matrix{LL mx[N];int rk,col;}sq[N];
matrix operator * (const matrix &a,const matrix&b){
    matrix c;
    memset(c.mx,0,sizeof(c.mx));
    for (int i=0;i<=a.rk;i++){
        for (int j=0;j<=b.rk;j++){
            c.mx[(i+j)%m]=(c.mx[(i+j)%m]+a.mx[i]*b.mx[j]%MOD)%MOD;
        }
    }
    c.rk=a.rk,c.col=b.col;
    return c;
}
matrix qpower(matrix a,LL k){
    matrix ans;
    memset(ans.mx,0,sizeof (ans.mx));
    ans.mx[0]=1;
    ans.rk=a.rk,ans.col=a.col;
    while (k){
        if (k&1)    ans=ans*a;
        a=a*a;
        k>>=1;
    }
    return ans;
}
int  main(){
    int t;
    cin>>t;
    while (t--){
        memset(sq,0,sizeof sq);
        cin>>n>>m;
        for(int i=0;i<=m-1;i++){
            arr[i]=n/m;
            sq[i].mx[0]=1;
            sq[i].mx[i]+=1;
            sq[i].rk=m-1,sq[i].col=1;
        }
        for (int i=1;i<=(int)(n%m);i++) arr[i]++;
        for (int i=0;i<=m-1;i++)    sq[i]=qpower(sq[i],arr[i]);
        for (int i=1;i<=m-1;i++)    {
            sq[i]=sq[i-1]*sq[i];
        }
        cout<<sq[m-1].mx[0]-1<<"\n";
    }
}