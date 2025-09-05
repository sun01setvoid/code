#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=10010;
int n,rt;
int h[N],e[N],ne[N],idx;
int d[N],f[N],vis[N];
int ma;
int flag=-1;
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;}
void dfs(int u,int deep){
    vis[u]=1;
    vector <int> v;
    if (h[u]==-1){
        if (deep>ma)    flag=u,ma=deep;
    }
    for (int i=h[u];~i;i=ne[i]){
        f[e[i]]=u;
        v.push_back(e[i]);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        dfs(v[i],deep+1);
    }
}
int main(){
    cin>>n;
    int a,b;
    memset(h,-1,sizeof h);
    for (int i=0;i<n;i++){
        cin>>a;
        while (a--){
            cin>>b;
            add(i,b);
            d[b]++;
        }
    }
    for (int i=0;i<n-1;i++){
        if (d[i]==0)    rt=i;
    }
    dfs(rt,1);
    cout<<ma<<endl;
    vector<int> ans;
    for (int i=flag;i!=rt;i=f[i]){
        ans.push_back(i);
    }
    ans.push_back(rt);
    cout<<ans[ans.size()-1];
    for (int i=ans.size()-2;i>=0;i--)    cout<<" "<<ans[i];
}