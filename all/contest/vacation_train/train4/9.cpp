//单后继，多前驱，那么我们反图
//从叶到根的一个处于范围内的是独立
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e4+10;
int deep[N],vis[N],visit[N];
int h[N],e[N],ne[N],idx;
int st[N],primes[N];
int a,b;
void add(int x,int y){
    e[idx]=y,ne[idx]=h[x],h[x]=idx,idx++;
};
bool dfs(int u){//单向树
    visit[u]=1;
    int flag=0;
    for (int i=h[u];~i;i=ne[i]){
        int j=e[i];
        deep[j]=deep[u]+1;
        if (dfs(j)){
            vis[u]=1;
            flag=1;
        }
    }
    if (a<=u && u<=b) flag=1;
    if (flag)   return true;
    else    return false;
}
int get(int x){
    int p=0;
    while (x){
       p=p*10+x%10;
       x/=10;
    }
    return p;
}
int sol(int x){
    int p=0;
    while (x){
        p+=(x%10)*(x%10);
        x/=10;
    }
    return p;
}
int main(){
    memset(h,-1,sizeof h);
    for (int i=2;i<=10000;i++){
        int m=sol(i);
        add(m,i);
    }
    int cnt=0;
    st[1]=1;
    for (int i=2;i<=10000;i++){
        if (!st[i]) primes[cnt++]=i;
        for (int j=0;primes[j]<=10000/i;j++){
            st[primes[j]*i]=1;
            if (i%primes[j]==0) break;
        }
    }
    cin>>a>>b;
    dfs(1);
    //对于1不可能有环，有环到不了1
    for (int i=a;i<=b;i++){
        if (!vis[i] && visit[i])    cout<<i<<" "<<deep[i]+deep[i]*(!st[i])<<endl;
    }
}