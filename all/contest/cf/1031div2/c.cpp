#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
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
#define pii pair<int,int>
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
int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    vector <vii> pre(n+1,vii(m+1,0));
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int mi = INT_MAX;
    int cnt = 0;
    for (int x=0;x<n;x++){
        for (int y=0;y<m;y++){
            if (grid[x][y]=='g'){
                ++pre[x+1][y+1];
                ++cnt;
            }
        }
    }
    for (int x=1;x<=n;x++){
        for (int y=1;y<=m;y++){
            pre[x][y]=pre[x][y]+pre[x][y-1]+pre[x-1][y]-pre[x-1][y-1];
            //cout<<pre[x][y];
        }
        //cout<<endl;
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (grid[x][y] != '.') continue;
            int x1 = max(x - k + 1,0LL);
            int x2 = min(x + k - 1,n-1);
            int y1 = max(y - k + 1,0LL);
            int y2 = min(y + k - 1, m-1 );
            //debug(x1);debug(x2);debug(y1);debug(y2);
            int in = pre[x2+1][y2+1]-pre[x1][y2+1]-pre[x2+1][y1]+pre[x1][y1];
            if (in < mi) {
                mi = in;
            }
        }
    }
    cout<<cnt-mi<<endl;
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