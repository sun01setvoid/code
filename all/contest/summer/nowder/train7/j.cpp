//https://acm.hdu.edu.cn/contest/problem?cid=1177&pid=1007
#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define ll long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e1 + 5;
const int mod = 998244353;
const ld eps = 1e-7;
//-----------------------------------------------------//
struct oo
{

};
int a, b, c, d;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int fast(int a, int b = mod - 2)
{
    if (b == 0)return 1;
    int ans = fast((a * a) % mod, b / 2);
    if (b & 1)ans = (ans * a) % mod; return ans;
}
int cal(int &aa,int &bb,int &cc,int &dd)
{
    int g = gcd(aa, cc);
    if (bb == dd)
    {
        aa = 1; cc = 1; return fast(g, bb);
    }
    else if (bb > dd)
    {
        bb -= dd; cc /= g; return fast(g, dd);
    }
    else
    {
        dd -= bb; aa /= g; return fast(g, bb);
    }
}
void Raze()
{
    cin >> a >> b >> c >> d; int ans = 1;
    while (1)
    {
        int tt=gcd(a,c);
        if(tt<=1)break;
        int val = cal(a, b, c, d);
        ans = (ans * val) % mod;
    }
    cout << (ll)ans << endl;

}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); int _ = 1;
    cin >> _;
    while (_--)Raze(); return 0;
}
