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
int n,k;
int state(int idx,int dir_idx,int r){
    return (idx*2+dir_idx)*k+r;
}
//-----------------------------------------------------//
void solve()
{
    cin >> n >> k;
    vector<int> p(n),d(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) cin >> d[i];
    int S=n*2*k;
    vector <int> out_dest (S,-1);
    vector <vii> rev(S);
    for (int i=0;i<n;i++){
        for (int dir_idx=0;dir_idx<2;dir_idx++){
            int dir=dir_idx==0?1:-1;
            for (int r=0;r<k;r++){
                int sid=state(i,dir_idx,r);
                int nd=(r==d[i]?-dir:dir);
                int ndir_idx=(nd==1?0:1);
                int j=i+nd;
                if (j<0 || j>=n) out_dest[sid]=-1;
                else{
                    int dist=abs(p[j]-p[i]);
                    int r2=(r+dist%k)%k;
                    int nid=state(j,ndir_idx,r2);
                    out_dest[sid]=nid;
                    rev[nid].push_back(sid);
                }
            }
        }
    }
    vector <int> good(S,0);
    queue <int> q;
    for (int sid=0;sid<S;sid++){
        if (out_dest[sid]<0){
            good[sid]=1;
            q.push(sid);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : rev[u]) {
            if (!good[v]) {
                good[v] = 1;
                q.push(v);
            }
        }
    }
        int qnum; cin >> qnum;
    vector<int> queries(qnum);
    for (int i = 0; i < qnum; ++i) cin >> queries[i];
    for (int x : queries) {
        auto it = lower_bound(p.begin(), p.end(), x);
        int i;
        int dir_idx;
        if (it == p.end()) {
            i = n - 1;
            dir_idx = 1;
        } else if (it == p.begin()) {
            i = 0;
            dir_idx = 0;
        } else {
            int ri = it - p.begin();
            int li = ri - 1;
            if (abs(p[li] - x) <= abs(p[ri] - x)) {
                i = li;
                dir_idx = 0;
            } else {
                i = ri;
                dir_idx = 1;
            }
        }

        int dist = abs(x - p[i]);
        int r = dist % k;
        int sid = state(i, dir_idx, r);
        if (good[sid]) YES;
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