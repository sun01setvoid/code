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
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
struct Node{
    int d;
    int u,v;
    bool operator>(const Node& other) const {
        return d > other.d;
    }//一定要有const
};
int find(int x,vii&p){
    if (x!=p[x]) return p[x]=find(p[x],p);
    return p[x];
}
void solve()
{
    int n,q,x,y;
    cin>>n>>q;
    vector <pii> a(n+q+1);
    int m=n;
    prq <Node,vector <Node>,greater<Node> > pq;
    vector <int> p(n+q+1);
    iota(p.begin(), p.end(), 0);
    //debugarr(p,1,n+1);
    for (int i=1;i<=n;i++){
        cin>>x>>y;
        a[i]={x,y};
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            pq.push({abs(a[i].fi-a[j].fi)+abs(a[i].se-a[j].se),i,j});
        }
    }
    while (q--){
        int dist=-1;
        int op;
        cin>>op;
        if (op==1){
            cin>>x>>y;
            a[n+1]={x,y};
            for (int i=1;i<=n;i++){
                pq.push({abs(a[i].fi-x)+abs(a[i].se-y),i,n+1});
            }
            n=n+1;
            m=m+1;
        }else if (op==2){
            if (m==1) cout<<-1<<endl;
            else{
                while (pq.size()){
                    auto [d,u,v]=pq.top();
                    int fu=find(u,p),fv=find(v,p);
                    if (fu==fv) pq.pop();
                    else{
                            if (dist==-1 || dist==d) p[fu]=fv,m--,dist=d,pq.pop();
                            else break;
                    }
                }
                cout<<dist<<endl;
            }
        }else{
            cin>>x>>y;
            cout<<(find(x,p)==find(y,p)?"Yes":"No")<<endl;
        }
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