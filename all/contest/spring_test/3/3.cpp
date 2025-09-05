#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair <int,int> PII;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T,n,m;
    cin>>T;
    while (T--){
        int cnt=0;
        cin>>n>>m;
        vector <vector <LL>> c(n+1,vector <LL>(m+1,0));
        vector <vector <LL>> w(n+1,vector <LL>(m+1,0));
        vector <LL> a(m+1,0);
        vector <priority_queue<PII,vector <PII>,greater <PII>>> pq(m+1);
        vector <int> err(n+1,0);
        queue <int> q;
        for (int i=1;i<=m;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++)  cin>>c[i][j];
            for (int j=1;j<=m;j++)  cin>>w[i][j];
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (c[i][j]>a[j])   err[i]++,pq[j].push({c[i][j],i});
            }
            if (err[i]==0)  q.push(i);
        }
        while (q.size()){
            auto it=q.back();
            q.pop();
            cnt++;
            for (int i=1;i<=m;i++){
                a[i]+=w[it][i];
                while (pq[i].size()){
                    auto t=pq[i].top();
                    if (a[i]<t.first) break;
                    err[t.second]--;
                    pq[i].pop();
                    if (err[t.second]==0)   q.push(t.second);
                }
            }
        }
        if (cnt==n) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    } 
}