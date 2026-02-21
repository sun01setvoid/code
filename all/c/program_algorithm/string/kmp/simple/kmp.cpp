// 模板
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define int long long
#define debug(x) cerr << #x << '=' << (x) << endl
#define vii vector<int>
#define pii pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 2 * maxn;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
string s1 = " ", s2 = " ";
int nxt[maxn];
void kmp(string &s)
{
    int n = s.size();
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[i] != s[j + 1])
            j = nxt[j];
        if (s[i] == s[j + 1]) ++j;
        nxt[i] = j;
    }
}
void solve()
{
    string s;
    cin >> s;
    s1 += s;
    cin >> s;
    s2 += s;
    kmp(s2);
    int n=s1.size();
    for (int i=1,j=0;i<=n;i++){
        while (j && s1[i]!=s2[j+1]) j=nxt[j];
        if (s1[i]==s2[j+1]) ++j;
        if (j==s2.size()-1){
            cout<<i-s2.size()+2<<endl;
            j=nxt[j];
        }
    }
    for (int i=1;i<=s2.size()-1;i++) cout<<nxt[i]<<" ";
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