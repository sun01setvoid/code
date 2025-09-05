#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarrn(a,st,en)             \
    cerr << #a << "=[";             \
    repn(i, st, en) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int p[maxn],mi[maxn];
//-----------------------------------------------------//
int find(int x){
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) p[i]=i,mi[i]=INF;
    vector <tuple<int,int,int>> e;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back(make_tuple(w,u,v));
    }
    int ans=LONG_LONG_MAX;
    sort(e.begin(),e.end());
    for (auto &edge :e){
        auto [w,u,v]=edge;
        int fu=find(u),fv=find(v);
        if (fu!=fv) {
            p[fu]=fv;
            mi[fv]=min({mi[fu],mi[fv],w});
            if (find(1)==find(n)){
                ans=min(ans,w+mi[find(1)]);
            }
        }
    }
    cout<<ans<<endl;
    ///把两个连通块连接起来的边是当前最大的边，其他的边都小于它
}
signed main()
{
    IOS;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
//连通->并查集->最小生成树（连通图每条边最小）
//1-n最小生成树上的点是无向最短路所经过的点（可以），不过生成树和最短路在边相同的情况下，都会有很多种，不一定对应
//但一定可以通过最小生成树求出最短路
//也就是正边dijikstra也一定是经过两点间最小的边
//dijikstra 和kruscal得到的边权一定是一样的
//二分答案双权值，固定一个，加上满足条件求另一个