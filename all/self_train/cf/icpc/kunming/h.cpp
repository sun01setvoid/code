#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
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
int n,k;
ld ans[z];
void solve(){
    cin>>n>>k;
    ld pi=acos(-1.0);
    for(int i=0;i<n;i++){
        ld x,y;cin>>x>>y;
        ans[i]=acos(x/sqrt(x*x+y*y));
        if(y<0)ans[i]=2*pi-ans[i];
    }
    sort(ans,ans+n);
    ld anss=0;
    for(int i=0;i<n;i++){
        int nx=(i+k)%n;
        ld t=0;
        if(nx>i){
            t=ans[nx]-ans[i];
        }else t=ans[nx]-ans[i]+2*pi;
        if(t>anss)anss=t;
    }
    cout << fixed << setprecision(10) << anss << endl;
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}