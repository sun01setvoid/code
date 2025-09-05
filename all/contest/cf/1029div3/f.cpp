#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n"
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
#define lb lower_bound
#define ub upper_bound
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
//-----------------------------------------------------//
int cnt=0;
int p[maxn];
vector <vii> G(maxn);
vii dist(maxn);
vii ans,mid;
void dfs(int u,int fa){
    if (G[u].size()>=3-(u==1)) cnt+=G[u].size()-2+(u==1);
    //debug(u);debug(G[u].size());
    if (G[u].size()==1-(u==1)) ans.pb(u);
    if (G[u].size()==3-(u==1)) mid.pb(u);
    for (auto &i:G[u]){
        if (i==fa) continue;
        dist[i]=dist[u]+1;
        dfs(i,u);
    }
}
void solve()
{
    int n;
    cnt=0;
    cin>>n;
    ans.clear(),mid.clear();
    for (int i=1;i<=n;i++) dist[i]=1,G[i].clear();
    for (int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,1);
    //debug(cnt);
    if (cnt==1){
        int res=p[abs(dist[ans[0]]-dist[ans[1]])];
        if (dist[ans[0]]==dist[ans[1]]) res+=1;
        else res+=p[abs(dist[ans[0]]-dist[ans[1]])-1];
        cout<<p[dist[mid[0]]]*res%mod<<endl;
    }else if (cnt==0){
        cout<<p[n]<<endl;
    }else cout<<0<<endl;
}
signed main()
{
    IOS;
    p[0]=1;
    for (int i=1;i<=2e5;i++) p[i]=p[i-1]*2%mod;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}