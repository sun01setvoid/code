#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define debug(x) cerr << #x << '=' << (x) << endl
#define debugarr(a, n)              \
    cerr << #a << "=[";             \
    rep1(i, n) cerr << a[i] << ' '; \
    cerr << ']' << endl
#define fi first
#define so second
//#define int long long
#define ld long double
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10;
const int maxm = 2e4 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//

struct oo
{

};
int n, a[maxn];
bitset<maxm>f;
void Raze()
{
    cin >> n; vii tmp; int sum = 0; f.reset(); f.set(0);
    for (int i = 1; i <= n; i++)cin >> a[i],sum += a[i];
    if (n <= 3) { YES; return; }
    int ma = 0; for (int i = 1; i <= n; i++)ma = max(ma, a[i]);
    if (ma * 6 <= sum) { NO; return; }
    if ((a[1] & 1) && (a[n] & 1))
    {
        bool flag = 0;
        for (int i = 2; i < n; i++)
        {
            if (a[i] & 1)flag = 1;
        }
        if (!flag) { YES; return; }
    }
    for (int i = 2; i < n; i++)tmp.pb(a[i]);
    sort(tmp.begin(), tmp.end());
    if (ma == a[n])
    {
        int mi = -1; int ts = a[1];
        for (int i = 0; i < tmp.size(); i++)
        {
            f |= (f << tmp[i]);
            int maxx = max(a[1], tmp[i]);
            ts += tmp[i];
            if (ts >= 2 * maxx)
            {
                for (int j = maxx; j <= ((mi == -1) ? ts - maxx : mi); j+=2)
                {
                    if (f.test(j))
                    {
                        mi = j; break;
                    }
                }
            }
            if (mi != -1)if (sum - mi - maxx - ma >= ma) { NO; return; }
        }
    }
    else if (ma == a[1])
    {
        int mi = -1; int ts = a[n];
        for (int i = 0; i < tmp.size(); i++)
        {
            f |= (f << tmp[i]);
            int maxx = max(a[n], tmp[i]);
            ts += tmp[i];
            if (ts  >= 2 * maxx)
            {
                for (int j = maxx; j <= ((mi == -1) ? ts - maxx : mi); j+=2)
                {
                    if (f.test(j))
                    {
                        mi = j; break;
                    }
                }
            }
            if (mi != -1)if (sum - mi - maxx - ma >= ma) { NO; return; }
        }
    }
    else
    {
        tmp.pop_back(); int mi = -1;
        //ma和1一组
        int tma = ma - a[1]; int ts = a[n];
        for (int i = 0; i < tmp.size(); i++)
        {
            f |= (f << tmp[i]);
            int maxx = max(tmp[i], a[n]);
            ts += tmp[i];
            if (ts >= 2 * maxx)
            {
                for (int j = maxx; j <= ((mi == -1) ? ts - maxx : mi); j+=2)
                {
                    if (f.test(j))
                    {
                        mi = j; break;
                    }
                }
            }
            if(mi!=-1)if (sum - mi - maxx - ma >= ma) {  NO; return; }
        }
        mi = -1;
        //ma和n一组
        f.reset(); f[0] = 1;
        tma = ma - a[n]; ts = a[1];
        for (int i = 0; i < tmp.size(); i++)
        {
            f |= (f << tmp[i]);
            int maxx = max(tmp[i], a[n]);
            ts += tmp[i];
            if (ts >= 2 * maxx)
            {
                for (int j = maxx; j <= ((mi == -1) ? ts - maxx : mi); j+=2)
                {
                    if (f.test(j))
                    {
                        mi = j; break;
                    }
                }
            }
            if (mi != -1)if (sum - mi - maxx - ma >= ma) {  NO; return; }
        }
    }
    YES;
}