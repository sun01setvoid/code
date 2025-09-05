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
    int px,py,qx,qy;
    cin>>n;
    cin>>px>>py>>qx>>qy;
    double sum=0,ma=0;
    vector <double> a(n+2);
    rep(i,1,n) {
        cin>>a[i],sum+=a[i],ma=max(a[i],ma);
    }
    double ans=sqrt((qx-px)*(qx-px)+(qy-py)*(qy-py));
    sum+=ans,ma=max(ma,ans);
    if (n==1) {
        cout<<(sum-ans==ans?"Yes":"No")<<endl;
        return;
    }
    if (ans==0){
        if (n==2) cout<<(a[1]==a[2]?"Yes":"No")<<endl;
        else{
            cout<<(sum-ma>=ma?"Yes":"No")<<endl;
        }
        return;
    }

    if (sum-ma>=ma) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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