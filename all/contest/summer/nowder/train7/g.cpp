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
const int z=1e6+10;
const int zz=1e6;
const int B=2000;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int pri[z],vis[z],cb[z],cnt;
void init(){
    cb[1]=0;
    for(int i=2;i<=zz;i++){
        if(!vis[i])pri[++cnt]=i,cb[i]=1;
        for(int j=1;j<=cnt;j++){
            if(i*pri[j]>zz)break;
            vis[i*pri[j]]=1;
            cb[i*pri[j]]=cb[i]+1;
            if(i%pri[j]==0)break;
        }
    }
}
void solve(){
    int n;cin>>n;
    vii tmp;
    for(int i=1;i<=n;i++)if(cb[i]%2)tmp.pb(i);
    for(int i=0;i<n/2;i++)cout<<tmp[i]<<" ";
    cout<<endl;
}
signed main(){
    IOS;
    init();
    int t=1;
    cin>>t;
    while(t--)solve();
}
