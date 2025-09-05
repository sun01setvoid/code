#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
const int z=2e5+10;
const int zz=2e5;
const int Z=1000000000;
const int inf=1e12;
const int mod=998244353;
void solve(){
    // int n=rand()%100+1,m=rand()%100+1,k=rand()%100+1,p=rand()%100+1;
    // while((n*m-(n*m)%2)<k*p||n==1||m==1||k*p%2==1||k*p==2){
    //     n=rand()%100+1,m=rand()%100+1,k=rand()%100+1,p=rand()%100+1;
    // }
    // cout<<n<<" "<<m<<" "<<k<<" "<<p<<endl;
    cout<<10000<<endl;
    for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)for(int l=1;l<=10;l++)for(int r=1;r<=10;r++)cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
}
signed main(){
    IOS;
    int t=1;
    //cin>>t;cout<<t<<endl;
    while(t--)solve();
}