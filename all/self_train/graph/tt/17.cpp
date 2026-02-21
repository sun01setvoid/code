//P1035
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define se second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int l[30],r[30];
void dfs(int rt){
    cout<<(char)(rt+'a'-1);
    if (l[rt]) dfs(l[rt]);
    if (r[rt]) dfs(r[rt]);
}
void solve()
{
    int n;
    cin>>n;
    string s;
    int rt=0;
    for (int i=1;i<=n;i++){
        cin>>s;
        if (s[1]!='*') l[s[0]-'a'+1]=s[1]-'a'+1;
        if (s[2]!='*') r[s[0]-'a'+1]=s[2]-'a'+1;
        if (i==1) rt=s[0]-'a'+1;
    }
    dfs(rt);
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