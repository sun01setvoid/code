#include<bits/stdc++.h>
using namespace std;
#define int long long
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
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int f=0,sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0)f=1;
        if(a[i]==1)sum++;
    }
    if(f)cout<<"NO\n";
    else{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]>2)cnt+=a[i]-2;
        }
        sum--;
        if(sum<=cnt+1)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}