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
#define debugarr(a,st, en)             \
    cerr << #a << "=[";             \
    rep(i,st,en) cerr << a[i] << ' '; \
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
    int s,b;
    cin>>s>>b;
    vii a(s+1);
    vector<pii> tmp;
    rep(i,1,s) cin>>a[i];
    rep(i,1,b){
        int d,g;
        cin>>d>>g;
        tmp.pb({d,g});
    }
    sort(tmp.begin(),tmp.end());
    for (int i=1;i<tmp.size();i++){
        tmp[i].se=tmp[i].se+tmp[i-1].se;
    }
    rep(i,1,s){
        auto it=ub(tmp.begin(),tmp.end(),make_pair(a[i],INF));
        if (it!=tmp.begin()){
            cout<<(*(--it)).se<<" ";
            continue;
        }
        cout<<0<<" ";
    }
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