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
const int z=2510;
int pri[z],vis[z],cnt;
int max(int a,int b){
	return a>b?a:b;
}
void init(){
	for(int i=2;i<z;i++){
		if(!vis[i])pri[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(pri[j]*i>=z)break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
void solve(){
	int n;cin>>n;
	map<int,int>mp,pm,a;
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		a[t]++;
	}
	for(auto p:a){
		int num=p.second;
		int t=p.first;
		for(int j=1;j<=cnt;j++){
			if(t<z&&!vis[t]){
				mp[t]+=num;
				pm[t]=max(pm[t],1ll);
				t=1;
				break;
			}
			if(t==1)break;
			int cnt=0;
			while(t%pri[j]==0){
				t/=pri[j];
				mp[pri[j]]+=num;
				cnt++;
			}
			pm[pri[j]]=max(pm[pri[j]],cnt);
		}
		if(t>1){
			pm[t]=max(pm[t],1ll);
			mp[t]+=num;
		}
	}
	int f=0;
	for(auto t:mp){
		if(t.second&1){
			f=1;
			break;
		}
		if(t.second<pm[t.first]*2){
			f=1;
			break;
		}
	}
	if(n%2)cout<<"YES\n";
	else{
		if(f)cout<<"NO\n";
		else cout<<"YES\n";
	}
}
signed main(){
    IOS;
    init();
    int t=1;
    cin>>t;
    while(t--)solve();
}