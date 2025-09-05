#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define drep(i,st,en) for (int i = (st); i >= (en); --i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define drepn(i,st,en) for (int i = (st); i > (en); --i)
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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int a[110][110];
bool cmp(pii &x,pii&y){
    return a[x.fi][x.se]>a[y.fi][y.se];
}
bool cmp1(pii &x,pii&y){
    return a[x.fi][x.se]>a[y.fi][y.se];
}
bool cmp2(pii&x,pii&y){
    return x.fi>y.fi;
}
bool cmp3(pii&x,pii&y){
    return x.se>y.se;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector <vii> G(10001);
    vector <pair<pii,pii>> e;
    vii d(10001,0);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;i++){
        vector <pii> b;
        for (int j=0;j<m;j++){
            b.pb({i,j});
        }
        sort(b.begin(),b.end(),cmp);
        for (int i=0;i<b.size()-1;i++){
            int x1=b[i].fi,y1=b[i].se,x2=b[i+1].fi,y2=b[i+1].se;
            G[x1*100+y1].pb(x2*100+y2);
            d[x2*100+y2]++;
        }
    }
    for (int j=0;j<m;j++){
        vector <pii> b;
        for (int i=0;i<n;i++){
            b.pb({i,j});
        }
        sort(b.begin(),b.end(),cmp);
        for (int i=0;i<b.size()-1;i++){
            int x1=b[i].fi,y1=b[i].se,x2=b[i+1].fi,y2=b[i+1].se;
            G[x1*100+y1].pb(x2*100+y2);
            d[x2*100+y2]++;
        }
    }
    bool f=0;
    vector <pii> ans;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (d[i*100+j]==0){
                ans.pb({i,j});
                //debug(i);debug(j);
                if (i==0 && j==0) f=1;
            }
        }
    }
    int sum=0;
    if (!f) ans.pb({0,0});
    sum+=(ans.size()-1)*114514;
    sort(ans.begin(),ans.end(),cmp);
    for (int i=0;i<ans.size()-1;i++){
        sum+=919810*abs(a[ans[i].fi][ans[i].se]-a[ans[i+1].fi][ans[i+1].se])+5141*abs(ans[i].se-ans[i+1].se)+114*abs(ans[i].fi-ans[i+1].fi);
    }
    cout<<sum<<endl;
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