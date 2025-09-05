#include <iostream>
using namespace std;
int st[1010],a[1010],res=2000,n,m;
void dfs(int x,int i,int temp){
    st[x]=1;
    if (x==0){
        res=min(res,temp);
        return;
    }
    if(i>m) return;
    if (x>=a[i] && !st[x-a[i]])
        dfs(x-a[i],i+1,temp+1),st[x-a[i]]=0;//dfs is a tree,recognise some mistakes,becasuse a single link can't influence another link,so just mark in the single link
    else if (x<a[i] && !st[a[i]-x])
        dfs(a[i]-x,i+1,temp+1),st[a[i]-x]=0;
    dfs(x,i+1,temp);
    st[x]=0;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<m;i++){
        cin>>a[i];
    }
    dfs(n,1,0);
    if (res==2000)  cout<<-1;
    else    cout<<res;
}