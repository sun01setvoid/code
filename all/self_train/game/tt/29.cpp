//非连续bash博弈，时间复杂度(n*sqrt(n))
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ull unsigned long long
#define ld long double
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
#define int long long 
#define pa pair<int,int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr<<#x<<'='<<(x)<<'\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int z=2e5+10;
const int zz=2e5;
const int B=500;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int cnt=0;
int a[z];
int f[z];
int sg(int u){
    if (!u) return 0;
    if (f[u]!=-1) return f[u];
    for (int i=1;i<=cnt;i++){
        if (a[i]>u) break;
        int t=sg(u-a[i]);
        if (!t) return f[u]=1;
    }
    return f[u]=0;
}
void solve(){
    memset(f,-1,sizeof f);
    int n,t;
    cin>>n>>t;
    for (int i=1;i<=t;i++) cin>>a[i];
    sort(a+1,a+t+1);
    cnt=unique(a+1,a+t+1)-a-1;
    int res=sg(n);
    if (res) {
        cout<<"Alice"<<endl;
    }else cout<<"Bob"<<endl;
}
signed main() {
    IOS;
    int t = 1;
    //cin >> t;
    while (t--) solve();
}