#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define vdebug(a)                       \
    cout << #a << "=[";                \
    for(auto x: a) cout << x << " ";    \
    cout << "]\n"
#define fi first
#define se second
#define int long long
#define ld long double
#define prq priority_queue
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 4e1 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n,ls[maxn],rs[maxn],dp[maxn][maxm],cost[maxn],siz[maxn];
void init()
{
    for(int i=1;i<=n;i++)
    {
        ls[i]=rs[i]=0;
        for(int j=0;j<=40;j++)dp[i][j]=INF;
    }
}
void dfs(int u)
{
    siz[u]=1;
    if(ls[u])dfs(ls[u]),siz[u]+=siz[ls[u]];
    if(rs[u])dfs(rs[u]),siz[u]+=siz[rs[u]];
    if(ls[u]&&rs[u])
    {
        dp[u][0]=siz[u];
        dp[u][1]=dp[ls[u]][0]+dp[rs[u]][0];
        for(int i=2;i<=40;i++)
        {
            int val1=dp[ls[u]][i-1]+dp[rs[u]][i-1];
            int val2=dp[ls[u]][i-2]+dp[rs[u]][i-1];
            int val3=dp[ls[u]][i-1]+dp[rs[u]][i-2];
            dp[u][i]=min(val1,min(val2,val3));
        }
    }
    else if(ls[u])
    {
        dp[u][0]=siz[u];
        dp[u][1]=dp[ls[u]][0];
        for(int i=2;i<=40;i++)
        {
            int val1=dp[ls[u]][i-1]+cost[i-1];
            int val2=dp[ls[u]][i-2]+cost[i-1];
            int val3=dp[ls[u]][i-1]+cost[i-2];
            dp[u][i]=min(val1,min(val2,val3));
        }
    }
    else if(rs[u])
    {
        dp[u][0]=siz[u];
        dp[u][1]=dp[rs[u]][0];
        for(int i=2;i<=40;i++)
        {
            int val1=dp[rs[u]][i-1]+cost[i-1];
            int val2=dp[rs[u]][i-2]+cost[i-1];
            int val3=dp[rs[u]][i-1]+cost[i-2];
            dp[u][i]=min(val1,min(val2,val3));
        }
    }
    else
    {
        dp[u][0]=1;dp[u][1]=0;
        for(int i=2;i<=40;i++)
        {
            dp[u][i]=cost[i-1]+cost[i-2];
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>ls[i]>>rs[i];
    dfs(1);int mi=INF;
    for(int i=0;i<=40;i++)mi=min(mi,dp[1][i]);
    cout<<mi<<endl;

}
signed main()
{
    IOS;
    int _ = 1;
    cost[0]=0;cost[1]=1;
    for(int i=2;i<=40;i++)cost[i]=cost[i-1]+cost[i-2]+1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}