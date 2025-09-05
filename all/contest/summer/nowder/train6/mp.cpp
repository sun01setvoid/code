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
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
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
const int mod=998244353;
int get(int p,vii &a){
    int sum=0,now=1;
    for(int i=a.size()-1;i>=0;i--){
        sum=(sum+a[i]*now%mod)%mod;
        now=now*p%mod;
    }
    return sum;
}
void solve(){
    int n,p;cin>>n>>p;
    vii a;vii aa;vii aaa;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        if(t>0)aa.pb(t);
    }
    sort(aa.begin(),aa.end());
    if(aa.size()==0){
        return;
    }
    int now=aa[0],cnt=1;
    for(int i=1;i<aa.size();i++){
        if(a[i]==now)cnt++;
        else{
            if(cnt==1)a.pb(now);
            cnt=1;
            now=a[i];
        }
    }
    if(cnt==1)a.pb(now);
    vii t1,t2;
    n=a.size();
    if(n%2){
        for(int i=0;i<=n/2;i++)t1.pb(a[i]);
        for(int i=n-1;i>n/2;i--)t2.pb(a[i]);
        int ans=(get(p,t1)-get(p,t2)+mod)%mod;
        cout<<ans<<endl;
    }else if(n==0){
        cout<<0<<endl;
    }else{
        int minn=1e9,mini=0;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<minn){
                minn=a[i]-a[i-1];
                mini=i;
            }
        }
        t1.pb(a[mini]);t2.pb(a[mini-1]);
        for(int i=0;i<mini-1;i++)aaa.pb(a[i]);
        for(int i=mini+1;i<n;i++)aaa.pb(a[i]);
        n-=2;
        for(int i=0;i<n/2-1;i++)t1.pb(aaa[i]);
        for(int i=n-1;i>n/2;i--)t2.pb(aaa[i]);
        int ans=(get(p,t1)-get(p,t2)+mod)%mod;
        cout<<ans<<endl;
    }
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}