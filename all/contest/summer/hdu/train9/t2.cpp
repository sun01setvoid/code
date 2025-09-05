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
const int z=1e4+10;
const int zz=1e4;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int fp(int a,int b,int p){
    int res=1;
    while(b){
        if(b%2)res=res*a%p;
        a=a*a%p;
        b/=2;
    }
    return res;
}
void solve(){
    int n;cin>>n;
    if(n<2000){
        int ans=0;
        int k=(n+118)/119;
        for(int i=1;i<n;i++){
            int t=(fp(i,n-2,n)+(1ll<<k))*(i+(1ll<<(k*2)));
            ans^=t;
        }
        ans%=mod;
        cout<<ans<<endl;
    }else{
        int t1=n;
        if(n%4==1)t1--;
        __int128 t2=(n-1)*(n-1)+1;
        int k=(n+118)/119;
        __int128 ans=t2+t1*(fp(2,k,mod)+fp(4,k,mod));
        ans=ans%mod;
        int res=ans;
        cout<<res<<endl;
    }
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}