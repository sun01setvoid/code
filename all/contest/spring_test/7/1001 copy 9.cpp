#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
//贪心错误，因为还要考虑大小一样的时候，所对应的最大值中选更多的，都一样->?
typedef pair<LL,int> PLI; 
struct node{
    int a;
    int b;
    LL c;
};
bool cmp(node &x,node &y){
    return x.c>y.c;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    int T;
    cin>>T;
    int ai,bi;
    LL wi;
    while (T--){
        cin>>n>>m;
        vector <node> prj;
        vector <int> vis(n+1,0),ug(m+1,0);
        vector <priority_queue<PLI>> pq(n+1);
        for (int i=0;i<m;i++){
            cin>>ai>>bi>>wi;
            prj.push_back({ai,bi,wi});
            pq[ai].push({wi,i});
            pq[bi].push({wi,i});
        }
        sort(prj.begin(),prj.end(),cmp);
        int cnt=0;
        LL ans=0;
        for (int i=0;i<m;i++){
            if (cnt==n) break;
            ug[i]=1;
            auto [u,v,q]=prj[i];
            if (vis[u] && vis[v])   {ug[i]=1;continue;}
            LL ma1=-1,ma2=-1;
            if (!vis[u]){
                ma1=0;
                while (pq[u].size()){
                    auto [s,t]=pq[u].top();
                    if (ug[t]){
                        pq[u].pop();
                        continue;
                    }
                    ma1=s;
                    break;
                }
            }
            if (!vis[v]){
                ma2=0;
                while (pq[v].size()){
                    auto [s,t]=pq[v].top();
                    if (ug[t]){
                        pq[v].pop();
                        continue;
                    }
                    ma2=s;
                    break;
                }
            }
            if (ma1>ma2 )    vis[v]=1;
            else vis[u]=1;
            ans+=q,cnt++;
        }
        cout<<ans<<"\n";
    }
}