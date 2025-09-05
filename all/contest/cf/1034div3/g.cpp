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
    int n,m,q;
    cin>>n>>m>>q;
    vii a(n+1);
    rep(i,1,n) cin>>a[i];
    vii facts;
    unordered_map <int,int> mp;
    int cnt = 0;
    for (int i=1;i*i<=m;i++){
        if (m%i==0){
            facts.pb(i);
            mp[i] = cnt++;
            if (i != m / i) {
                facts.pb(m / i);
                mp[m / i] = cnt++;
            }
        }
    }
    vector <vii> circles(cnt, vii(n+1, 0));
    vector <int> ans(cnt,0);
    for (auto &x:facts){
        for (int i=2;i<=n;i++){
            if (a[i]%x<a[i-1]%x){
                circles[mp[x]][i] = 1;
                ans[mp[x]]++;
            }
        }
    }
    while (q--){
        int op,x,y;
        cin>>op;
        if (op==1){
            cin>>x>>y;
            a[x]=y;
            for (auto &f:facts){
                if (x>1 && a[x]%f<a[x-1]%f && circles[mp[f]][x] == 0){
                    circles[mp[f]][x] = 1;
                    ans[mp[f]]++;
                }else if (x>1 && a[x]%f>=a[x-1]%f && circles[mp[f]][x] == 1){
                    circles[mp[f]][x] = 0;
                    ans[mp[f]]--;
                }
                if (x<n && a[x]%f>a[x+1]%f && circles[mp[f]][x+1] == 0){
                    circles[mp[f]][x+1] = 1;
                    ans[mp[f]]++;
                }else if (x<n && a[x]%f<=a[x+1]%f && circles[mp[f]][x+1] == 1){
                    circles[mp[f]][x+1] = 0;
                    ans[mp[f]]--;
                }
            }
        }else{
            cin>>y;
            int d=__gcd(m,y);
            debug(ans[mp[d]]);
            if (ans[mp[d]]<m/d) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
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