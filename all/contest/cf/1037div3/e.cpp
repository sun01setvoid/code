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
    int n;
    cin>>n;
    vii p(n+1,0),s(n+1,0);
    rep(i,1,n) cin>>p[i];
    rep(i,1,n) cin>>s[i];
    if (p[n]!=s[1]){
        cout<<"NO"<<endl;
        return;
    }
    int d=p[n];
    bool f=1;
    for (int i=1;i<=n-1;i++){
        if (p[i]%p[i+1]!=0){
            f=0;
            break;
        }
    }
    for (int i=n;i>=2;i--){
        if (s[i]%s[i-1]!=0){
            f=0;
            break;
        }
    }
    for (int i=1;i<n;i++){
        if (__gcd(p[i],s[i+1])!=d){
            f=0;
            break;
        }
    }
    cout<<(f?"YES":"NO")<<endl;
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