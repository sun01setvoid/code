#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
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
const int z=5e4+10;
const int zz=5e4;
const int B=1ll<<7;
const int inf=0x3f3f3f;
const int mod=1e9+7;
int num[10]={119,36,93,109,46,107,123,37,127,111};
int lowbit(int x){
	return x&-x;
}
int a[110];
vii all;
int n,m,ans;
void dfs(int st,int nw){
	if(nw>=ans)return;
	int cur=-1;
	for(auto v:all){
		if((v&st)==0){  //&上所有各不相同，等于&所有的异或不等于0
            cur=v;
			break;
		}
	}
	if(cur==-1){
		ans=nw;
		return;
	}
	while(cur)dfs(st|lowbit(cur),nw+1),cur-=lowbit(cur);
}
void solve(){
	cin>>n>>m;ans=inf;all.clear();
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		int p=1,nb=0;
		for(int j=0;j<m;j++){
			nb+=num[t%10]*p;
			t/=10;
			p*=B;
		}
		a[i]=nb;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]^a[j])all.pb(a[i]^a[j]);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	dfs(0,0);
	cout<<ans<<endl;
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
}