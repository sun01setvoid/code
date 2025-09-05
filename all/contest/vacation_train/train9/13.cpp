#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define inf 0x3f3f3f3f
struct Node{
    int r,c;
};
struct pep{
    int ord;
    int val;
};
bool cmp(pep& a,pep& b){
    return a.val<b.val;
}
int n,m;
int stx,sty;
pep p[10010];
int vis[110][110];
int mp[110][110];
int ans[110][110];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void bfs(){
    queue <Node> q;
    ans[stx][sty]=0;
    q.push({stx,sty});
    while (q.size()){
        auto t=q.front();
        q.pop();
        int x=t.r,y=t.c;
        vis[x][y]=1;
        for (int i=0;i<4;i++){
            int xi=x+dir[i][0],yi=y+dir[i][1];
            if (xi<1 || xi>m || yi<1 || yi>n || mp[xi][yi]==0)    continue;
            if (!vis[xi][yi]){
                vis[xi][yi]=1;
                ans[xi][yi]=ans[x][y]+1;
                q.push({xi,yi});
            }
        }
    }
}
int main(){
    int a,b;
    memset(ans,0x3f,sizeof ans);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++){
            cin>>mp[i][j];
            if (mp[i][j]==2)    stx=i,sty=j;
        }
    bfs();
    int k;
    cin>>k;
    map <int,int> num;
    for (int i=1;i<=k;i++){
        cin>>a>>b;
        if (ans[b][a]!=0x3f3f3f3f)
        {p[i].val=ans[b][a];num[ans[b][a]]++;}
        p[i].ord=i;
    }
    sort(p+1,p+k+1,cmp);
    int id=-1;
    for (int i=1;i<=k;i++){
        if (num[p[i].val]==1)    {id=i;break;}
    }
    if (id==-1)    cout<<"No winner.";
    else    cout<<p[id].ord<<" "<<p[id].val;
}