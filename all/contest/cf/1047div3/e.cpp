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
const int maxn = 1e6 + 10;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
//-----------------------------------------------------//
int a[maxn], cnt[maxn];
void solve()
{
    int n, k;
    cin >> n >> k;
    int cur = 1;
    for (int i = 0; i <= n; i++)
        cnt[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    if (!cnt[0])
    {
        if (k & 1)
            cout << 0 << endl;
        else
            cout << n << endl;
    }
    else if (cnt[0] >= 2)
    {
        if (k == 1)
        {
            int mex = 0;
            int ans = 0, num = 0, ansnum = 0;
            while (cnt[mex])
            {
                num += cnt[mex];
                if (cnt[mex] >= 2)
                    ansnum += cnt[mex];
                else
                    ans += mex;
                mex++;
            }
            ans += ansnum * mex + (n - num) * mex;
            cout << ans << endl;
        }
        else if (k >= 2)
        {
            if ((k - 1) & 1)
            {
                cout << 0 << endl;
            }
            else
                cout << n << endl;
        }
    }
    else
    {
        int id = -1;
        int mex = 0;
        int ans1 = 0, num = 0, ansnum = 0, ans = 0;
        while (cnt[mex])
        {
            num += cnt[mex];
            if (cnt[mex] >= 2)
                ansnum += cnt[mex], id = mex;
            else
                ans1 += mex;
            mex++;
        }
        ans = ans1 + ansnum * mex + (n - num) * mex;
        if (k == 1)
            cout << ans << endl;
        else
        {
            if (ansnum == 0)
            {
                if (mex == n || mex == n - 1)
                    cout << ans << endl;
                else if ((k - 1) & 1)
                {
                    cout << (mex - 1) * mex / 2 + (n - mex) * (mex + 1) << endl;
                }
                else
                {
                    cout << (mex - 1) * mex / 2 + (n - mex) * mex << endl;
                }
            }
            else if ((k - 1) & 1)
            {
                cout << (id - 1) * id / 2 + (n - id) * id << endl;
            }
            else
            {
                cout << (id - 1) * id / 2 + (n - id) * (id + 1) << endl;
            }
        }
    }
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