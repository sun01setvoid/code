//P1020 导弹拦截
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
int n;
//-----------------------------------------------------//
int lowbit(int x){
    return x&-x;
}
void add(int x,int val,vii &tr){
    for (int i=x;i<=n;i+=lowbit(i)){
        tr[i]=max(tr[i],val);
    }
}
int query(int x,vii &tr){
    int ans=0;
    for (int i=x;i>=1;i-=lowbit(i)){
        ans=max(ans,tr[i]);
    }
    return ans;
}
void solve()
{
    int tmp;
    vii a,b;
    while(cin>>tmp) b.pb(tmp),a.pb(tmp);
    n=a.size();
    sort(b.begin(),b.end());
    map<int,int> mp1,mp2;
    int cnt=0;
    rep (i,0,n-1){
        if (!mp1.count(b[i])) mp1[b[i]]=++cnt;
    }
    cnt=0;
    drep(i,n-1,0){
        if (!mp2.count(b[i])) mp2[b[i]]=++cnt;
    }
    vii tr1(n+1,0),tr2(n+1,0);
    int ans1=1,ans2=1;
    for (int i=0;i<n;i++){
        int val1=query(mp1[a[i]]-1,tr1),val2=query(mp2[a[i]],tr2);
        ans1=max(val1+1,ans1),ans2=max(val2+1,ans2);
        add(mp1[a[i]],val1+1,tr1);add(mp2[a[i]],val2+1,tr2);
    }
    cout<<ans2<<endl<<ans1;
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