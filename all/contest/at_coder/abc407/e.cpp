#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, st, en) for (int i = (st); i <= (en); ++i)
#define repn(i, st, en) for (int i = (st); i < (en); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr1(a, n)             \
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
#define pii pair<int, int>
#define pb push_back
#define prq priority_queue
#define eb emplace_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
void solve()
{
    //2k+1个位置，至少有k+1个左括号，且这样的条件就行了，贪心:使能选择左括号的区间尽量大，就是只选k+1个，最后偶数的一定成立
    int n;
    cin>>n;
    vector <int> a(2*n+1);
    prq <int> pq;
    int cnt=0;
    int res=0;
    for (int i=1;i<=2*n;i++){
        cin>>a[i];
        pq.push(a[i]);
        while (cnt<(i+1)/2){
            int t=pq.top();
            pq.pop();
            res+=t;
            cnt++;
        }
    }
    cout<<res<<endl;
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