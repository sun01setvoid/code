#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int ans[100010];
int cnt;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
map <string,int> vis;
map <string,int> a;
int n,m;
void dfs(int x,int y){
    string s=to_string(x)+" "+to_string(y);
    vis[s]=1;
    if (a[s]>=2)    ans[cnt]=1;
    for (int i=0;i<=3;i++){
        int xi=x+dir[i][0],yi=y+dir[i][1];
        if (xi<1 || xi>n || yi<1 || yi>m)    continue;
        string s1=to_string(xi)+" "+to_string(yi);
        if (!vis.count(s1) && a[s1])    dfs(xi,yi);
    }
}
int main(){
    cin>>n>>m;
    int temp;
    string s;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            s=to_string(i)+" "+to_string(j);
            scanf("%1d",&temp);
            a[s]=temp;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            s=to_string(i)+" "+to_string(j);
            if (!vis.count(s) && a[s]){
                ++cnt;
                dfs(i,j);
            }
        }
    }
    int res=0;
    for (int i=1;i<=cnt;i++){
        if (ans[i])    res++;
    }
    cout<<cnt<<" "<<res;
}