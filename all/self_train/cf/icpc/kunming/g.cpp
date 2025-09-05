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
const int B=50000;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int ans;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void dfs(int a,int b,int sum){
    if(sum>=ans)return;
    int t=gcd(a,b);
    a/=t;b/=t;
    if(a==1||b==1){
        sum+=2;
        ans=min(ans,sum);
        return;
    }
    dfs(a-1,b,sum+1);
    dfs(a,b-1,sum+1);
}
void solve(){
    int a,b;cin>>a>>b;ans=inf;
    dfs(a,b,0);
    cout<<ans<<endl;
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}