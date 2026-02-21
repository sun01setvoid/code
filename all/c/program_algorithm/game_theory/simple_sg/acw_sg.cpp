#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 6010;
int h[N], e[N], ne[N], idx;
int f[N], n, m, k;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx, idx++;
}
int sg(int u)
{
    if (f[u] != -1)
        return f[u];
    unordered_map<int, int> T;
    int v = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        T[sg(j)] = 1;
    }
    if (T.count(0)) f[u]=1;
    else f[u]=0;
    return f[u];
    // T空就是0
}
int main()
{
    // 初始化dp起点呢？
    // f[0]=0?
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    memset(f, -1, sizeof f);
    int a, b, res = 0, tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        res ^= sg(tmp);
    }
    if (res)
        cout << "win";
    else
        cout << "lose";
}
/*
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <set>
using namespace std;
const int N=6010;
int h[N],e[N],ne[N],idx;
int f[N],n,m,k;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;
}
int sg(int u){
    if (f[u]!=-1)   return f[u];
    set <int> S;
    for (int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        S.insert(sg(j));
    }
    for (int i=0;;i++){
        if (!S.count(i))    {f[u]=i;return f[u];}
    }
}
int main(){
    cin>>n>>m>>k;
    memset(h,-1,sizeof h);
    memset(f,-1,sizeof f);
    int a,b,res=0,tmp;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        add(a,b);
    }
    for (int i=0;i<k;i++){
        cin>>tmp;
        res^=sg(tmp);
    }
    if (res)
        cout<<"win";
    else
        cout<<"lose";
}
*/