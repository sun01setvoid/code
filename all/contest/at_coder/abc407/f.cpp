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
void solve()
{
    int n;
    cin>>n;
    vii ans(n+3);
    vector <pii> a(n+1);
    rep(i,1,n) cin>>a[i].fi,a[i].se=i;
    sort(a.begin()+1,a.end());
    set <int> vis;
    vis.insert(0),vis.insert(n+1);
    drep(i,n,1){
        auto idx=vis.upper_bound(a[i].se);
        auto ind=idx;--ind;
        int r=*idx-a[i].se-1,l=a[i].se-*ind-1;
        int xmin=min(l,r),xmax=max(l,r);
        ans[1]+=a[i].fi;
        ans[1+xmin+1]-=a[i].fi;
        ans[1+xmax+1]-=a[i].fi;
        ans[1+xmin+xmax+2]+=a[i].fi;
        vis.insert(a[i].se);
    }
    rep(i,1,n)  ans[i]=ans[i-1]+ans[i];
    rep(i,1,n)  ans[i]=ans[i-1]+ans[i];
    rep(i,1,n)  cout<<ans[i]<<endl;
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