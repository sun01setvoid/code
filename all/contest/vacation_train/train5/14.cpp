#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair <int,int> PII;
const int N=210,M=10010;
int dist[N],st[N],n,m,g[N][N],num[N];
string reft[N];
vector <int> p[N];
vector <int> path;
vector <int> res;
int sz=0,pe=0,cnt=0;
unordered_map <string,int> mp;
void dijkstra(){//dijiksta类似于bfs以最短路径长度分层，取得一个最短路径，就是确定了一个点，逐层进行，且从1开始蔓延，dp状态转移
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for  (int i=1;i<=n;i++){
        int t=-1;
        for (int j=1;j<=n;j++){
            if (!st[j] && (t==-1 || dist[t]>dist[j]))
                t=j;
        }
        if (dist[t]==0x3f3f3f3f)
            break;
        st[t]=1;
        for (int j=1;j<=n;j++){
            if (!st[j] && g[t][j]!=0x3f3f3f3f)
                if (dist[j]>dist[t]+g[t][j]){
                    dist[j]=dist[t]+g[t][j];
                    p[j].clear();
                    p[j].push_back(t);
                    //二：我们使用前面的已经做好的更新且前面的点的路径一定确定好了,且这里是新的最短路径
                    //所以可以设v[],记录点的数量
                    //w[]记录侵略大本营的数量
                    //p[]记录前一个
                    //path[]记录最短路径的条数，因为以的最短路径分层，所以之前找到最短路径的点，一定知道他有多少条，path[j]=path[t]
                    //path[1]=1;
                }
                else if (dist[j]==dist[t]+g[t][j])  p[j].push_back(t);//注意重边！！！，g[][]当然没有
                //在else if 中path[j]+=path[t];
                //如果cnt[t]+1 比之前已经做过的cnt[j]多,更改cnt[],w[],p[]
                //如果一样，比较w[t]+num[j]与w[j],更新cnt[],w[],p[]
        }
    }
}
//终点的最短路，一定是由他前驱节点的最短路更新而来的，而这个前驱节点显然由贪心得到，当最短路径已经是到终点时，其余的还未使用的前驱节点都不用使用
//使用的是前面的已经找到最短路的前驱节点(最短路的值小于到终点的最短路的值)，然后更新终点，得到某几条路径是到终点的最短路径
//所以递归下去，求许多条最短路径，就是用dijkstra
//记录dfs的一条路径类似于栈，push && pop
void dfs(int x){
    path.push_back(x);
    if (x==1){
        cnt++;
        if (path.size()>sz) {
            sz=path.size();res=path;
            int sum=0;
            for (int i=0;i<sz;i++){
                sum+=num[path[i]];
            }
            pe=sum;
        }
        else if (path.size()==sz){
            int sum=0;
            for (int i=0;i<sz;i++){
                sum+=num[path[i]];
            }
            if (sum>pe) pe=sum,res=path;
        }   
    }
    for (auto & i:p[x]) dfs(i);
    path.pop_back();
}
int main(){
    memset(g,0x3f,sizeof g);
    cin>>n>>m;
    string a,b;
    int c;
    cin>>a>>b;
    mp[a]=1;mp[b]=n;
    reft[1]=a,reft[n]=b;
    int ord=1;
    for (int i=1;i<n;i++){
        cin>>a>>c;
        if (!mp.count(a))   mp[a]=++ord;
        num[mp[a]]=c;
        reft[mp[a]]=a;
    }
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        g[mp[a]][mp[b]]=g[mp[b]][mp[a]]=c;
    }
    dijkstra();
    dfs(n);
    cout<<reft[res[sz-1]];
    for (int i=sz-2;i>=0;i--)   cout<<"->"<<reft[res[i]];
    cout<<endl;
    cout<<cnt<<" "<<dist[n]<<" "<<pe;
}
