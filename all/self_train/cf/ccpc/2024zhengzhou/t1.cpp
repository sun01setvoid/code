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
const int maxn = 1e3 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-12;
//-----------------------------------------------------//
int a[maxn],b[maxn],mp[maxn][maxn],ed[maxn],ed1[maxn];
int n,k,q;
void solve()
{
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    int now=0,sum=0;
    for(int i=1;i<=100;i++)for(int j=1;j<=n;j++){
        now=max(now,a[j]+(i-1)*k);
        mp[i][j]=now+b[j];
        now+=b[j];
    }
    now=0;
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
                int d1=0,h1=0;
                int t1=mp[x][y]-1;
                int tt1=t1/k;
                if(tt1*k==t1){
                    d1=tt1-1;
                    h1=t1-(tt1-1)*k;
                }else{
                    d1=tt1;
                    h1=t1-tt1*k;
                }
                d1++;
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
                if(d!=d1||h!=h1){
                    cout<<x<<" "<<y<<endl;
                    cout<<"ans1:"<<d<<" "<<h<<endl;
                    cout<<"ans2:"<<d1<<" "<<h1<<endl;
                }
            }else{
                int d1=0,h1=0;
                int t1=mp[x][y]-1;
                int tt1=t1/k;
                if(tt1*k==t1){
                    d1=tt1-1;
                    h1=t1-(tt1-1)*k;
                }else{
                    d1=tt1;
                    h1=t1-tt1*k;
                }
                d1++;
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
                if(d!=d1||h!=h1){
                    cout<<x<<" "<<y<<endl;
                    cout<<"ans1:"<<d<<" "<<h<<endl;
                    cout<<"ans2:"<<d1<<" "<<h1<<endl;
                }
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
                int d1=0,h1=0;
                int t1=mp[x][y]-1;
                int tt1=t1/k;
                if(tt1*k==t1){
                    d1=tt1-1;
                    h1=t1-(tt1-1)*k;
                }else{
                    d1=tt1;
                    h1=t1-tt1*k;
                }
                d1++;
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
                if(d!=d1||h!=h1){
                    cout<<x<<" "<<y<<endl;
                    cout<<"ans1:"<<d<<" "<<h<<endl;
                    cout<<"ans2:"<<d1<<" "<<h1<<endl;
                }
            }else{
                int d1=0,h1=0;
                int t1=mp[x][y]-1;
                int tt1=t1/k;
                if(tt1*k==t1){
                    d1=tt1-1;
                    h1=t1-(tt1-1)*k;
                }else{
                    d1=tt1;
                    h1=t1-tt1*k;
                }
                d1++;
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
                if(d!=d1||h!=h1){
                    cout<<x<<" "<<y<<endl;
                    cout<<"ans1:"<<d<<" "<<h<<endl;
                    cout<<"ans2:"<<d1<<" "<<h1<<endl;
                }
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