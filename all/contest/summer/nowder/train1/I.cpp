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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
struct node{
    int cost,b;
    bool operator <(const node&u){
        if (cost!=u.cost) return b>u.b;
        return cost<u.cost;
    }
    bool operator >(const node&u){
        if (cost!=u.cost) return b<u.b;
        return cost>u.cost;
    }
};
int lowbit(int x){
    return x&-x;
}
//-----------------------------------------------------//
void solve()
{
    int n;
    cin>>n;
    vii a(n+1),ans(n+1);
    for (int i=1;i<=n;i++)  ans[i]=-1;
    rep(i,1,n) cin>>a[i];
    vector<vector<set<node>>> dp(n+1,vector<set<node>>(n+1));
    for (int i=1;i<=n;i++) dp[i][i].insert({0,0});
    for (int len=2;len<=n;len++){
        for (int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            for (int k=i;k<=j-1;k++){
                int g=log2(2*(j-i+1)+1);
                int val=min(k-i+1,j-k)*g;
                int val1=-1,val2=-1;
                for (auto it=dp[i][k].begin();it!=dp[i][k].end();it++){
                    if ((*it).b<=abs(j-k-(k-i+1))){
                        val1=(*it).cost;
                        break;
                    }
                }
                for (auto it=dp[k][j].begin();it!=dp[k][j].end();it++){
                    if ((*it).b<=abs(j-k-(k-i+1))){
                        val2=(*it).cost;
                        break;
                    }
                }
                if (val1==-1 || val2==-1) continue;
                //auto t1=dp[i][k].lower_bound({0,abs(j-k-(k-i+1))});
                //if (t1==dp[i][k].end()) continue;
                //auto t2=dp[k+1][j].lower_bound({0,abs(j-k-(k-i+1))});
                dp[i][j].insert({val+val1+val2,abs(j-k-(k-i+1))});
                if (i==1 &&j==n) ans[k]=val+val1+val2;
            }
        }
    }
    for (int i=1;i<=n-1;i++) cout<<ans[i]<<" ";
    cout<<endl;
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