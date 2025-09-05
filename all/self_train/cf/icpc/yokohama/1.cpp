#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
#define ll long long
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
#define pa pair<int,int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr<<#x<<'='<<(x)<<'\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*
        _/_/_/     _/_/_/_/_/_/_/
      _/                 _/
     _/                  _/
     _/                  _/
     _/                  _/
      _/                 _/
        _/_/_/           _/
*/
//再不卷就退役了 
const int z=3e7+10;
const int zz=3e7;
const int B=2000;
//const int inf=1e12;
const int mod=1e9+7;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    double na=a,nb=b,nc=c;
    double mxans=0,ai=0,aj=0;
    for(double i=0.700;i<=0.700;i+=0.05){
        for(double j=0.950;j<=0.950;j+=0.05){
            double x1=i,y1=j+nc;
            double x2=na+i,y2=na+nc-i;
            double x3=2*na+nb-i,y3=nc+nb-j;
            double x4=-j,y4=nc+i;
            double ans1=sqrt(x1*x1+y1*y1);
            double ans2=sqrt(x2*x2+y2*y2);
            double ans3=sqrt(x3*x3+y3*y3);
            double ans4=sqrt(x4*x4+y4*y4);
            printf("%.3lf %.3lf %.3lf\n",x1,y1,ans1);
            printf("%.3lf %.3lf %.3lf\n",x2,y2,ans2);
            printf("%.3lf %.3lf %.3lf\n",x3,y3,ans3);
            printf("%.3lf %.3lf %.3lf\n",x4,y4,ans4);
            cout<<"AWA\n";
            double nowans=ans1;
            if(nowans>ans2)nowans=ans2;
            if(nowans>ans3)nowans=ans3;
            if(nowans>ans4)nowans=ans4;
            if(mxans<nowans){
                mxans=nowans;
                ai=i;aj=j;
            }
        }
    }
    printf("%.3lf %.3lf %.3lf\n",mxans,ai,aj);
}
signed main(){
    //IOS;
    int t=1;
    //cin>>t;
    while(t--)solve();
}