#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define fi first
#define so second
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
const int maxn = 1e5 + 5;
const int maxk = 1e6 + 5;
const int maxm = 1e0 + 5;
const int mod = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;
struct oo
{

};
int mp[maxn][maxm], n;
int cnt[maxk][maxm];
void solve()
{
    cin >> n; int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)cin >> mp[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)cnt[mp[i][j]][j]++;
    }
    map<int, int>mp1, mp2, mp3;
    //           2-3, 1-3, 1-2
    for (int i = 1; i <= n; i++)
    {
        mp1[mp[i][2] * 1e7 + mp[i][3]]++;
        mp2[mp[i][1] * 1e7 + mp[i][3]]++;
        mp3[mp[i][1] * 1e7 + mp[i][2]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int t1=mp1[mp[i][2] * 1e7 + mp[i][3]]-1;
        int t2=mp2[mp[i][1] * 1e7 + mp[i][3]]-1;
        int t3=mp3[mp[i][1] * 1e7 + mp[i][2]]-1;
        int c1=cnt[mp[i][1]][1] - t2-t3-1;
        int c2=cnt[mp[i][2]][2] - t1-t3-1;
        int c3=cnt[mp[i][3]][3] - t1-t2-1;
        ans += c1*c2+c1*c3+c2*c3;
        ans += t1*t2+t1*t3+t2*t3;
        ans += (c1+c2+c3)*(t1+t2+t3);
        ans += t1*(t1-1)/2+t2*(t2-1)/2+t3*(t3-1)/2;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); int _ = 1;
    //cin >> _;
    while (_--)solve(); return 0;
}