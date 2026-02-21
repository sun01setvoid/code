
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
const int maxn = 1000;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
int gd[maxn][maxn];
int sg(int a, int b)
{
    if (a + a * a >= b)
        return b - a;
    if (b <= 1000 && gd[a][b] != -1) // 感觉有点问题，越界访问了
        return gd[a][b];
    set<int> s;
    for (int i = 1; i <= a * a; i++)
    {
        int t = sg(a + i, b);
        s.insert(t);
    }
    for (int i = 0;; i++)
    {
        if (!s.count(i))
        {
            gd[a][b] = i;
            break;
        }
    }
    return gd[a][b];
}
void solve()
{
    memset(gd, -1, sizeof gd);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int b, a;
        cin >> b >> a;
        if (b == 0 || a == 0)
            res ^= 0;
        else
        {
            int t = sg(a, b);
            res ^= t;
        }
    }
    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
/*
 //这题的难点在于发现局势sg值是可以转移的。
 int SG(int s,int c)
 {
   int t=sqrt(s);
   while(t*t+t>=s)//找第一个满足t*t+t<s的t
   {
     t--;
   } 
   if(c>t) return s-c;//先手必赢
   else if(c==t) return 0;//先手必输
   else return SG(t,c);//判断能否取到t,c状态 //这里能发现给定一个必败态，很好求sg值
 }
*/