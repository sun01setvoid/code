#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0)
const int z=1e6+10;
int a[z],n;
vector<int>G[z];
map<int,vector<int>>mp;
vector<pair<int,int>>P[z];
pair<int,int> dfs(int now,int fa){
	mp[fa].push_back(now); 
	pair<int,int>ans,temp;
	ans={0,now};
	for(auto t:G[now]){
		if(t==fa)continue;
		temp=dfs(t,now);
		ans.first+=temp.first;
		ans.second=min(ans.second,temp.second);
		P[now].push_back(temp);
	}
	ans.first++;
	return ans;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		int t;cin>>t;
		G[a[t]].push_back(a[i]);
		G[a[i]].push_back(a[t]);
	}
	int now=0;
	for(int i=0;i<n;i++){
		if(G[i].size()==1){
			now=i;
			break;
		}
	}
	dfs(now,-1);
	queue<pair<int,int>>q;
	q.push({now,now});
	while(q.size()){
		auto cur=q.front();
		q.pop();
		int a=cur.first,b=cur.second;
		int len=0;
		for(auto t:P[a])len+=t.first;
		len=n-1-len;
		P[a].push_back({len,b});
		for(auto t:mp[a]){
			q.push({t,min(now,t)});
		}
	}
	for(int i=0;i<n;i++){
		int cnt=0;
		int maxn=0;
		for(auto t:P[i]){
			cnt+=(t.second<i);
			maxn=max(maxn,t.first);
		}
		if(cnt>1)cout<<0<<" ";
		else cout<<maxn<<" ";
	}
	cout<<n<<endl;
}
signed main(){
	IOS;
	int t=1;
	while(t--)solve();
}