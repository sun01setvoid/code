//P1436 谁能赢呢
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
//完美匹配
signed main()
{
    IOS;
    int n = 1;
    while (cin>>n)
    {
        if (n==0) break;
        if (n&1) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}