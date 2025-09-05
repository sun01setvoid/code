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
    int n,x,y,z;cin>>n>>x>>y>>z;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    if(x==y){
        int ans=n*x;
        cout<<ans<<endl;
        return;
    }
    int len=(x-z+x-y-1)/(x-y);
    //if(len<=1)len=2;
    vector<int>tmp;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1])cnt++;
        else{
            if(cnt>1)tmp.push_back(cnt);
            cnt=1;
        }
    }
    if(cnt>1)tmp.push_back(cnt);
    sort(tmp.rbegin(),tmp.rend());
    if(tmp.size()==0){
        int ans=n*x;
        cout<<ans<<endl;
    }else if(tmp.size()<len){
        int sum=0;
        for(int i=0;i<tmp.size();i++)sum+=tmp[i];
        int ans=(sum-1)*y+(n-sum+1)*x;
        cout<<ans<<endl;
    }else{
        int sum=0;
        for(int i=0;i<len-1;i++)sum+=tmp[i];
        int t2=tmp[len-1];
        sum-=(len-1)*t2;
        int zz=t2-1,yy=sum,xx=n-yy-zz;
        int ans=xx*x+yy*y+zz*z;
        cout<<ans<<endl;
    }
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}