#include <iostream>
#define int long long
using namespace std;
const int N=1e6+10,MOD=1e9+7;
int p[N],v[N],e[N],s[N];
int find(int x){
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
signed main(){
    int t;
    cin>>t;
    while (t--){
        int n,m,k;
        cin>>n>>m>>k;
        int ma=max(n,m);
        for (int i=0;i<ma;i++){
            for (int j=0;j<ma;j++)  p[i*ma+j]=i*ma+j,v[i*ma+j]=1,s[i*ma+j]=0,e[i*ma+j]=0;
        }
        int a1,b1,a2,b2;
        bool f=1;
        cin>>a1>>b1;
        --a1,--b1;
        for (int i=1;i<=k;i++){
            cin>>a2>>b2;
            --a2,--b2;
            if (abs(a1-a2)+abs(b1-b2)!=2) f=0;
            else {
                if (a1==a2){
                    int fx=find(a1*ma+(b1+b2)/2);
                    if (v[fx]>e[fx]) e[fx]++,s[fx]=1;
                    else f=0;
                }
                else if (b1==b2){
                    int fx=find(b1+(a1+a2)/2*ma);
                    if (v[fx]>e[fx]) e[fx]++,s[fx]=1;
                    else f=0;
                }
                else {
                    int fx=find(a1*ma+b2),fy=find(a2*ma+b1);
                    if (fx==fy) {
                        if (v[fy]>e[fy]) e[fy]++;
                        else f=0;
                    }
                    else if (e[fx]<v[fx] || e[fy]<v[fy]){
                        //cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<" ";
                        //cout<<"fx="<<fx<<"\n";
                        //cout<<"fy="<<fy<<"\n";
                        p[fx]=fy;
                        v[fy]+=v[fx];
                        e[fy]+=e[fx]+1;
                        //cout<<e[fy]<<"\n\n";
                        s[fy]=s[fy]|s[fx];
                    }
                    else f=0;
                }
            }
            a1=a2,b1=b2;
        }
        if (!f) cout<<0<<"\n";
        else {
            int ans=1;
            for (int i=0;i<ma*ma;i++){
                if (p[i]==i){
                    if (v[i]>e[i]) ans=ans*v[i]%MOD; 
                    else{
                        if (!s[i]) ans=ans*2%MOD; 
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
}
//一定不会和输入（提供）的点交叉
//不会重复，n*m进制不对,必须是前面n*m的话，n要大于等于m
//自环表示只有一种选择
