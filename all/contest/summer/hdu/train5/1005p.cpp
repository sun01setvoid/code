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
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
unordered_map<int,int>mp;
int a,b,c,d,ans;
int k[4][1100];
int cg(int aa,int bb,int cc,int dd){
    return aa*1000000000+bb*1000000+cc*1000+dd;
}
void dfs(int na,int nb,int nc,int nd,int ka,int kb,int kc,int kd,int sum){
    //cout<<na<<" "<<nb<<" "<<nc<<" "<<nd<<endl; 
    ans=max(ans,sum);
    int now=cg(na,nb,nc,nd);
    if(!mp.count(now)||mp[now]<sum)mp[now]=sum;
    else return;
    if(ka<=k[0][0]){
        if(na)dfs(na-1,nb,nc,nd,ka+1,kb,kc,kd,sum+k[0][ka]);
        if(nb)dfs(na+1,nb-1,nc,nd,ka+1,kb,kc,kd,sum+k[0][ka]);
        if(nc)dfs(na,nb+1,nc-1,nd,ka+1,kb,kc,kd,sum+k[0][ka]);
        if(nd)dfs(na+1,nb+1,nc,nd-1,ka+1,kb,kc,kd,sum+k[0][ka]);
    }
    if(kb<=k[1][0]){
        if(nb)dfs(na,nb-1,nc,nd,ka,kb+1,kc,kd,sum+k[1][kb]);
        if(nc)dfs(na+1,nb,nc-1,nd,ka,kb+1,kc,kd,sum+k[1][kb]);
        if(nd)dfs(na,nb+1,nc,nd-1,ka,kb+1,kc,kd,sum+k[1][kb]);
    }
    if(kc<=k[2][0]){
        if(nc)dfs(na,nb,nc-1,nd,ka,kb,kc+1,kd,sum+k[2][kc]);
    }
    if(kd<=k[3][0]){
        if(nd)dfs(na,nb,nc,nd-1,ka,kb,kc,kd+1,sum+k[3][kd]);
    }
}
bool cmp(int x,int y){
    return x>y;
} 
void solve(){
    cin>>a>>b>>c>>d;
    for(int i=0;i<4;i++){
        cin>>k[i][0];
        for(int j=1;j<=k[i][0];j++)cin>>k[i][j];
        sort(k[i]+1,k[i]+1+k[i][0],cmp);
    }
    dfs(a,b,c,d,1,1,1,1,0);
    cout<<ans<<endl;
    mp.clear();ans=0;
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}