#include <iostream>
#include <cstring>
using namespace std;
const int N=10010,M=10010;
int h[N],e[M],ne[M],idx;
int vis[N];
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
int main(){
    memset(h,-1,sizeof h);
    int n,m;
    cin>>n>>m;
    int k;
    int a,b;
    for (int i=1;i<=m;i++){
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    while (k--){
        memset(vis,0,sizeof vis);
        cin>>a;
        for (int i=1;i<=a;i++){
            cin>>b;
            vis[b]=1;
        }
        bool f=1;
        for (int i=1;i<=n;i++){
            if (vis[i])    continue;
            for (int j=h[i];~j;j=ne[j]){
                int v=e[j];
                if (!vis[v])    {f=0;break;}
            }
            if (f==0)    break;
        }
        if (f)    cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}