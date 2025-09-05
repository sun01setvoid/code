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
    vii a(n+1),vis(n+1); 
    int sum=0;
    rep(i,1,n){
        cin>>a[i];
        sum+=a[i];
    }
    int ans1=0,ans2=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            int tmp=a[i]^a[j];
            ans1+=tmp;
            bool f=1;
            int val=0;
            for (int k=0;k<=30;k++){
                if (tmp>>k&1){
                    if (f) val+=1<<k,f=0;
                    else f=1;
                }
            }
            ans2+=val;
        }
    }
    debug(ans1);debug(ans2);
    debug(sum);
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