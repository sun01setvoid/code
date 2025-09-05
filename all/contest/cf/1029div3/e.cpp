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
#define lb lower_bound
#define ub upper_bound
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
    vii a(n+1),b(n+1);
    vector <vii> posa_even(n+1),posa_odd(n+1),posb_even(n+1),posb_odd(n+1);;
    rep(i,1,n) {
        cin>>a[i];
        if (i&1) posa_odd[a[i]].pb(i);
        else posa_even[a[i]].pb(i);
    }
    rep(i,1,n) {
        cin>>b[i];
        if (i&1) posb_odd[b[i]].pb(i);
        else posb_even[b[i]].pb(i);
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        int t1=posa_even[i].size(),t2=posa_odd[i].size();
        int s1=posb_even[i].size(),s2=posb_odd[i].size();
        if (t1 && t2) ans=max(min(posa_even[i].back(),posa_odd[i].back()),ans);
        if (t1>=2) ans=max(posa_even[i][t1-2],ans);
        if (t2>=2) ans=max(posa_odd[i][t2-2],ans);
        if (s1 && s2) ans=max(min(posb_even[i].back(),posb_odd[i].back()),ans);
        if (s1>=2) ans=max(posb_even[i][s1-2],ans);
        if (s2>=2) ans=max(posb_odd[i][s2-2],ans);
        if (t1 && s1) ans=max(min(posa_even[i].back(),posb_even[i].back()),ans);
        if (t2 && s2) ans=max(min(posa_odd[i].back(),posb_odd[i].back()),ans);
        if (t1 && s2){
            auto it=lb(posa_even[i].begin(),posa_even[i].end(),posb_odd[i][s2-1]-1);
            if (it!=posa_even[i].begin()){
                ans=max(*(--it),ans);
            }
            it=lb(posb_odd[i].begin(),posb_odd[i].end(),posa_even[i][t1-1]-1);
            if (it!=posb_odd[i].begin()){
                ans=max(*(--it),ans);
            }
        }
        if (t2 && s1){
            auto it=lb(posa_odd[i].begin(),posa_odd[i].end(),posb_even[i][s1-1]-1);
            if (it!=posa_odd[i].begin()){
                ans=max(*(--it),ans);
            }
            it=lb(posb_even[i].begin(),posb_even[i].end(),posa_odd[i][t2-1]-1);
            if (it!=posb_even[i].begin()){
                ans=max(*(--it),ans);
            }
        }
        //debug(ans);
    }
    cout<<ans<<endl;
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