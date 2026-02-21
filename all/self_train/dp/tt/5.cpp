//P2010 乌龟棋   //ac极限
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
const int maxn = 400;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n,m;
int a[maxn],b[maxn];
int cnt[5];
map <array<int,4>,int> dp[maxn];
int dfs(int pos,int c1,int c2,int c3,int c4){ //实际是f[a][b][c][d]
    int ans=0;
    if (dp[pos].count({c1,c2,c3,c4})) return dp[pos][{c1,c2,c3,c4}];
    if (pos==n) return 0;
    if (c1>=1) ans=max(ans,dfs(pos+1,c1-1,c2,c3,c4)+a[pos+1]);
    if (c2>=1) ans=max(ans,dfs(pos+2,c1,c2-1,c3,c4)+a[pos+2]);
    if (c3>=1) ans=max(ans,dfs(pos+3,c1,c2,c3-1,c4)+a[pos+3]);
    if (c4>=1) ans=max(ans,dfs(pos+4,c1,c2,c3,c4-1)+a[pos+4]);
    return dp[pos][{c1,c2,c3,c4}]=ans;
}
//-----------------------------------------------------//
void solve()
{
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    int tmp;
    rep(i,1,m){
        cin>>tmp;
        cnt[tmp]++;
    }
    cout<<dfs(1,cnt[1],cnt[2],cnt[3],cnt[4])+a[1];
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
//P2010 乌龟棋   //tle
/*
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
const int maxn = 400;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
int n,m;
int a[maxn],b[maxn];
int cnt[5];
map <array<int,3>,int> dp[maxn];
int dfs(int pos,int c2,int c3,int c4){
    int ans=0;
    if (pos==n) return 0;
    if (dp[pos].count({c2,c3,c4})) return dp[pos][{c2,c3,c4}];
    if (n-pos-2*c2-3*c3-4*c4>=1) ans=max(ans,dfs(pos+1,c2,c3,c4)+a[pos+1]);
    if (c2>=1) ans=max(ans,dfs(pos+2,c2-1,c3,c4)+a[pos+2]);
    if (c3>=1) ans=max(ans,dfs(pos+3,c2,c3-1,c4)+a[pos+3]);
    if (c4>=1) ans=max(ans,dfs(pos+4,c2,c3,c4-1)+a[pos+4]);
    return dp[pos][{c2,c3,c4}]=ans;
}
//-----------------------------------------------------//
void solve()
{
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    int tmp;
    rep(i,1,m){
        cin>>tmp;
        cnt[tmp]++;
    }
    cout<<dfs(1,cnt[2],cnt[3],cnt[4])+a[1];
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
*/