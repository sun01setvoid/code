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
    int n,k;
    cin>>n>>k;
    vii a(n+1),b(n+1),c(n+1);
    for (int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    int cnt=0;
    sort(b.begin()+1,b.end());
    for (int i=1;i<=n;i++){
        if (a[i]<=b[k]){
            c[++cnt]=a[i];
        }
    }
    bool f=1;
    int ans=0;
    for (int i=1,j=cnt;i<=j;i++){
        if (c[i]==b[k]){
            if (i!=j && c[j]==b[k]) ans+=2,--j;
            else if (i==j)   ans+=1,--j;
        }else{
            while (c[j]==b[k]) --j;
            if (i!=j && c[i]==c[j]) ans+=2,--j;
            else if (i!=j && c[i]!=c[j]){
                f=0;
                break;
            }else if (i==j) ans+=1,--j;
        }
    }
    if (!f){
        NO;
        return;
    }
    else {
        if (ans>=k-1) YES;
        else NO;
    }
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