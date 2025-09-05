#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 3e2 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
void solve()
{
    int n=rand()%100+3;
    int m=rand()%100+1;m=max(m,n-2);m=min(m,n*(n-1)/2);
    int d=rand()%50+1;
    cout<<n<<" "<<m<<" "<<d<<endl;
    map<pair<int,int>,int>mp;
    for(int i=1;i<=m;i++){
        int u=rand()%n+1,v=rand()%n+1;
        while(mp[{u,v}]){
            u=rand()%n+1,v=rand()%n+1;
        }
        cout<<u<<" "<<v<<endl;
        mp[{u,v}]=1;mp[{v,u}]=1;
    }
    int k=rand()%(n-2);
    cout<<k<<endl;
    map<int,int>vis;
    for(int i=1;i<=k;i++){
        int t=rand()%(n-2)+1;
        while(t==1||t==n||vis[t])t=rand()%(n-2)+1;
        cout<<t<<" ";
    }
    cout<<endl;
}
signed main()
{
    IOS;
    int _ = 1;
    srand(time(0));
    cin >> _;
    cout<<_<<endl;
    while (_--)
    {
        solve();
    }
    return 0;
}