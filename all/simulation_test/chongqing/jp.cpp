#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500013;
int f[N],vis[N];
vector<int>mp[N];
int d[N];
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1,x,y;i<n;i++) cin>>x>>y,mp[x].push_back(y),mp[y].push_back(x),d[x]++,d[y]++;
    s=' '+s;
    queue<int>q;
    int ans=n;
    for(int i=1;i<=n;i++)if(d[i]==1)q.push(i);
    while(!q.empty()) {       //考虑删除已考虑过连续的点
        int x=q.front();
        q.pop();
        ans--;
        for(auto i:mp[x])if(s[i]==s[x]) {
            --d[i];
            if(d[i]==1)q.push(i);
        }
    }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--)solve();
}