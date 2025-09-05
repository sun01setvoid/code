#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr1(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define debugarr0(a, n)             \
    cerr << #a << "=[";             \
    rep0(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define se second
#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                 \
ios::sync_with_stdio(false); \
cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
void solve(){
    int n,m;
    cin>>n>>m;
    string res;
    cin>>res;
    map<string,set<int>> mp; 
    rep1(i,m){
        string p="##";
        getchar();
        char a,b;
        cin>>a>>b;
        if (a!='a' && a!=b){
            p[0]=a,p[1]=b;
            mp[p].insert(i);
        } 
    }
    rep0(i,n){
        if (res[i]!='a'){
            if (res[i]=='b'){
                if (mp.count("ba") && !mp["ba"].empty()){
                    auto& t=mp["ba"];
                    res[i]='a';
                    t.erase(t.begin());
                }
                else if (mp.count("bc") && mp.count("ca") && !mp["bc"].empty() && !mp["ca"].empty()){
                    auto& t=mp["bc"];
                    auto pos=*t.begin();
                    auto& it=mp["ca"];
                    auto idx=it.upper_bound(pos);
                    if (idx==it.end()) continue;
                    res[i]='a';
                    mp["bc"].erase(pos),it.erase(*idx);
                }
            }else{
                if (mp.count("ca") &&!mp["ca"].empty()){
                    auto& t=mp["ca"];
                    res[i]='a';
                    t.erase(t.begin());
                }
                else if (mp.count("cb") && !mp["cb"].empty()){
                    auto& t1=mp["cb"];
                    res[i]='b';
                    auto pos=*t1.begin();
                    t1.erase(t1.begin());
                    if (mp.count("ba") && !mp["ba"].empty()){
                        auto& t=mp["ba"];
                        auto idx=t.upper_bound(pos);
                        if (idx==t.end()) continue;
                        t.erase(*idx);
                        res[i]='a';
                    }
                }
            }
        }
    }
    cout<<res<<endl;
}
signed main(){
    IOS;
    int _=1;
    cin>>_;
    while (_--){
        solve();
    }
    return 0;
}