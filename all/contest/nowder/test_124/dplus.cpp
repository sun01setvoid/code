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
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int p[maxn],cnt[maxn];
vector <int> G[maxn];
int find (int x){
    if (x!=p[x]) p[x]=find(p[x]);
    return  p[x];
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    p[fx]=fy;
}
void solve()
{
    int n;
    int ans=0;
    cin>>n;
    vii  w(n+1);
    map<int,vii,greater<int>> pos;
    rep(i,1,n) cin>>w[i],pos[w[i]].pb(i);
    rep(i,1,n-1){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);G[v].pb(u);
        ans+=(w[u]==w[v])*2;
    }
    rep(i,1,n) p[i]=i;
    vii cnt(n+1);
    vii node;
    node.reserve(n+1);
    for (const auto &[val, p]: pos) {
        node.clear();
        for (int x: p) {
            for (int y: G[x]) {
                if (w[y] <= w[x]) {
                    continue;
                }
                int f = find(y);
                if (cnt[f]++ == 0) {
                    node.push_back(f);
                }
            }
        }
        for (int x: node) {
            ans += cnt[x] * (cnt[x] - 1);
            cnt[x] = 0;
        }
        for (int x: p) {
            for (int y: G[x]) {
                if (w[y] >= w[x]) {
                    merge(x, y);
                }
            }
        }
    }
    cout<<ans;
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