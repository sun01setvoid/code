#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=1e1;
int h[N],e[N],ne[N],w[N],idx;
int dist[N],st[N],f[N],n,p,k,g;
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx,idx++;
}
vector <int> alls;
vector <int> movd;
vector <int> ins;
int find1(int x){
    return lower_bound(alls.begin(),alls.end(),x)-alls.begin();
}
int find2(int x){
    return lower_bound(movd.begin(),movd.end(),x)-movd.begin();
}
void spfa(int u){
    memset(dist,0x3f,sizeof dist);
    dist[u]=0;
    queue <int>q;
    q.push(u),st[u]=1;
    while (q.size()){
        int t=q.front();
        q.pop();
        st[t]=0;
        for (int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if (dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                if (!st[j]){
                    q.push(j);
                    st[j]=1;
                }
            }
        }
    }
}
int main(){
    cin>>n>>p>>k>>g;
    int xi;
    memset(h,-1,sizeof h);
    alls.push_back(g);
    for (int i=0;i<p;i++){
        cin>>xi;
        alls.push_back(xi);
        ins.push_back(xi);
    }
    for (int i=0;i<k;i++){
        cin>>xi;
        alls.push_back(xi);
        movd.push_back(xi);
    }
    sort(alls.begin(),alls.end());
    sort(movd.begin(),movd.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    int t,l1,l2,l3;
    for (int i=1;i<(int)(alls.size());i++){
        int item=alls[i];
        if (binary_search(movd.begin(),movd.end(),item)){
            t=find2(item);
            if (t>0 && t<(int)(movd.size()))
            {
                l1=find1(movd[t-1]),l2=find1(movd[t]);
                add(l1,l2,1);
                add(l2,l1,1);
            }
        }
        add(i-1,i,alls[i]-alls[i-1]);
        add(i,i-1,alls[i]-alls[i-1]);
    }
    spfa(find1(g));
    for (int i=0;i<(int)ins.size();i++){
        auto x=find1(ins[i]);
        cout<<dist[x]<<" ";
    }
}
    