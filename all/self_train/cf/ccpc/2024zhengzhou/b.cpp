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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6+10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int n,k,q;
int a[maxn],b[maxn],ed[maxn],ed1[maxn];
void solve()
{
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    int now=0,sum=0;
    for(int i=1;i<=n;i++){
        now=max(now,a[i]);
        ed[i]=now+b[i];
        now+=b[i];
        sum+=b[i];
    }
    if(sum<=k){
        int bg=now%k;
        for(int i=1;i<=n;i++){
            bg=max(bg,a[i]);
            ed1[i]=bg+b[i];
            bg+=b[i];
        }
        while(q--){
            int x,y;cin>>x>>y;
            if(x==1){
                int d=0,h=0;
                int t=ed[y]/k;
                if(t*k==ed[y])t--;
                h=ed[y]-t*k;
                d=t+x;
                h--;
                if(h==0){
                    h=k;
                    d--;
                }
                cout<<d<<" "<<h<<endl;
            }else{
                int d=0,h=0;
                int t=ed1[y]/k;
                if(t*k==ed1[y])t--;
                h=ed1[y]-t*k;
                d=t+x;
                h--;
                if(h==0){
                    h=k;
                    d--;
                }
                cout<<d<<" "<<h<<endl;
            }
        }
    }else{
        int dm=sum-k;
        int ad=now/k-1;
        int bg=now%k;
        for(int i=1;i<=n;i++){
            bg=max(bg,a[i]);
            ed1[i]=bg+b[i];
            bg+=b[i];
        }
        while(q--){
            int x,y;cin>>x>>y;
            if(x==1){
                int d=0,h=0;
                int t=ed[y]/k;
                if(t*k==ed[y])t--;
                h=ed[y]-t*k;
                d=t+x;
                h--;
                if(h==0){
                    h=k;
                    d--;
                }
                cout<<d<<" "<<h<<endl;
            }else{
                int d=0,h=0;
                int t=(ed1[y]+dm*(x-2))/k;
                if(t*k==ed1[y]+dm*(x-2))t--;
                h=ed1[y]+dm*(x-2)-t*k;
                d=t+x+ad;
                h--;
                if(h==0){
                    h=k;
                    d--;
                }
                cout<<d<<" "<<h<<endl;
            }
        }
    }
    
}
signed main()
{
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}