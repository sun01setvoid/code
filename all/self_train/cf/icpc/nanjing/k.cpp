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
const int z=1e5+10;
const int zz=1e5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int n,m,k,w;
int a[z],b[z],f;
vii ans;
void op(int L,int R,int l,int r){
    vii tmp;
    int pr=-k;
    for(int i=l;i<=r;i++){
        if(a[i]<=pr+k)continue;
        int now=a[i];
        if(now+k<=R)    tmp.pb(now);
        else{
            now=R-k;
            if(now<L){
                f=1;
                return;
            }
            int pp=now;
            for(int i=tmp.size()-1;i>=0;i--){
                if(tmp[i]+k>=pp){
                    tmp[i]=pp-k-1;
                    pp=tmp[i];
                }else break;
                if(pp<L){
                    f=1;
                    return;
                }
            }
            tmp.pb(now);
        }
        pr=now;
    }
    for(auto t:tmp)ans.pb(t);
}
void solve(){
    cin>>n>>m>>k>>w;ans.clear();k--;f=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    b[m+1]=w+1;a[n+1]=w+2;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int pl=1,pr=1;
    for(int i=1;i<=m+1;i++){
        pl=pr;
        while(a[pr]<b[i])pr++;
        if(pr==pl)continue;
        if(b[i]-b[i-1]-1<k){
            cout<<-1<<endl;
            return;
        }
        op(b[i-1]+1,b[i]-1,pl,pr-1);
        if(f){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)   cout<<ans[i]<<" ";
    cout<<endl;
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}
