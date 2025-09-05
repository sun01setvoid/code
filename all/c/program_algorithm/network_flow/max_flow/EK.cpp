#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i,st,en) for (int i = (st); i > (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1010;
const int maxm = 20010;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n,m,S,T;
int h[maxn],e[maxm],f[maxm],ne[maxm],idx;
//f表示这条边在残余网络中最多能流多少
int q[maxn],d[maxn],pre[maxn]; //d当前所有边的容量最小值
bool st[maxn];
//-----------------------------------------------------//
//<=O(n*m*m) 1000-10000
void add(int a,int b,int c){ //idx从0开始
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}
bool bfs(){
    int hh=0,tt=-1;
    memset(st,false,sizeof st);
    q[++tt]=S,st[S]=true,d[S]=INF;
    while (hh<=tt){
        int t=q[hh++];
        for (int i=h[t];~i;i=ne[i]){
            int ver=e[i];
            if (!st[ver]&&f[i]){
                st[ver]=true;
                d[ver]=min(d[t],f[i]);
                pre[ver]=i;
                if (ver==T) return true;
                q[++tt]=ver;
            }
        }
    }
    return false;
}
int EK(){
    int r=0;
    while (bfs()){
        r+=d[T];
        for (int i=T;i!=S;i=e[pre[i]^1]){
            f[pre[i]]-=d[T],f[pre[i]^1]+=d[T];
        }
    }
    return r;
}
void solve()
{
    cin>>n>>m>>S>>T;
    rep(i,0,n) h[i]=-1;
    rep(i,0,m-1){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<EK()<<endl;
}
signed main()
{
    IOS;
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}