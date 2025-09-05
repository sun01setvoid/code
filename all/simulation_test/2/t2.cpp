#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ls p << 1
#define rs p << 1 | 1
#define fi first
#define se second
#define pa pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const int z = 2e5 + 10;
const int zz = 2e5;
const int Z = 1000000000;
const int inf = 1e12;
const int mod = 998244353;
char ans[110][110];
int vis[110][110];
int n, m, p, k;
int brr[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int _ = 1;
void out()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            vis[i][j] = 0;
    int cnt = 0;
    int x = 1, y = 1, p = 0, f = 0;
    while (!f && !vis[x][y])
    {
        vis[x][y] = 1;
        if (x < 1 || y < 1 || x > n || y > m)
        {
            f = 1;
            break;
        }
        if (ans[x][y] == 'r')
        {
            if (p == 0)
                p = 1;
            else if (p == 3)
                p = 2;
            else
                f = 1;
            x += brr[p][0];
            y += brr[p][1];
            cnt++;
        }
        else if (ans[x][y] == '-')
        {
            if (p == 1 || p == 3)
            {
                x += brr[p][0];
                y += brr[p][1];
                cnt++;
            }
            else
                f = 1;
        }
        else if (ans[x][y] == '|')
        {
            if (p == 0 || p == 2)
            {
                x += brr[p][0];
                y += brr[p][1];
                cnt++;
            }
            else
                f = 1;
        }
        else if (ans[x][y] == '7')
        {
            if (p == 1)
                p = 2;
            else if (p == 0)
                p = 3;
            else
                f = 1;
            x += brr[p][0];
            y += brr[p][1];
            cnt++;
        }
        else if (ans[x][y] == 'J')
        {
            if (p == 1)
                p = 0;
            else if (p == 2)
                p = 3;
            else
                f = 1;
            x += brr[p][0];
            y += brr[p][1];
            cnt++;
        }
        else if (ans[x][y] == 'L')
        {
            if (p == 2)
                p = 1;
            else if (p == 3)
                p = 0;
            else
                f = 1;
            x += brr[p][0];
            y += brr[p][1];
            cnt++;
        }
        else
            f = 1;
    }
    if (x != 1 && y != 1 && cnt != p * k)
    {
        cout << n << " " << m << " " << p << " " << k << endl;
    }
}
void solve()
{
    cin >> n >> m >> p >> k;
    int sum = p * k;
    int ssum = n * m;
    ssum -= ssum % 2;
    if (n == 1 || m == 1 || sum % 2 == 1 || ssum < sum || sum == 2)
        ;
    else
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                ans[i][j] = '.';
        if (n == 2)
        {
            ans[1][1] = 'r';
            ans[2][1] = 'L';
            int t = sum / 2;
            for (int i = 2; i < t; i++)
                ans[1][i] = ans[2][i] = '-';
            ans[1][t] = '7';
            ans[2][t] = 'J';
            out();
        }
        else if (m == 2 || n * 2 >= sum)
        {
            ans[1][1] = 'r';
            ans[1][2] = '7';
            int t = sum / 2;
            for (int i = 2; i < t; i++)
                ans[i][1] = ans[i][2] = '|';
            ans[t][1] = 'L';
            ans[t][2] = 'J';
            out();
        }
        else
        {
            int t = sum / n;
            if (t % 2)
            {
                for (int i = 1; i <= t + 1; i += 2)
                {
                    ans[1][i] = 'r';
                    ans[1][i + 1] = '7';
                    for (int j = 2; j < n - 1; j++)
                        ans[j][i] = ans[j][i + 1] = '|';
                    ans[n - 1][i] = 'J';
                    ans[n - 1][i + 1] = 'L';
                    ans[n][i] = ans[n][i + 1] = '-';
                }
                ans[n - 1][1] = '|';
                ans[n][1] = 'L';
                ans[n - 1][t + 1] = '|';
                ans[n][t + 1] = 'J';
                sum -= n * (t - 1);
                sum /= 2;
                for (int i = 1; i <= n - sum; i++)
                    ans[i][t] = ans[i][t + 1] = '.';
                ans[n - sum + 1][t] = 'r';
                ans[n - sum + 1][t + 1] = '7';
                out();
            }
            else
            {
                for (int i = 1; i <= t; i += 2)
                {
                    ans[1][i] = 'r';
                    ans[1][i + 1] = '7';
                    for (int j = 2; j < n - 1; j++)
                        ans[j][i] = ans[j][i + 1] = '|';
                    ans[n - 1][i] = 'J';
                    ans[n - 1][i + 1] = 'L';
                    ans[n][i] = ans[n][i + 1] = '-';
                }
                ans[n - 1][1] = '|';
                ans[n][1] = 'L';
                ans[n - 1][t] = '|';
                sum -= n * t;
                int now = t;
                for (int i = 1; i <= n; i++)
                    ans[i][now] = '.';
                if (sum == 0)
                {
                    ans[1][now] = '7';
                    ans[n][now] = 'J';
                    for (int i = 2; i < n; i++)
                        ans[i][now] = '|';
                    out();
                }
                else if (sum % 2)
                {
                    for (int i = 1; i <= sum; i += 2)
                    {
                        ans[i][now] = 'L';
                        ans[i][now + 1] = '7';
                        ans[i + 1][now] = 'r';
                        ans[i + 1][now + 1] = 'J';
                    }
                    ans[sum + 1][now] = '.';
                    ans[1][now] = '-';
                    ans[n][now] = '-';
                    ans[n][now + 1] = 'J';
                    for (int i = sum + 1; i < n; i++)
                        ans[i][now + 1] = '|';
                    out();
                }
                else
                {
                    for (int i = 1; i <= sum; i += 2)
                    {
                        ans[i][now] = 'L';
                        ans[i][now + 1] = '7';
                        ans[i + 1][now] = 'r';
                        ans[i + 1][now + 1] = 'J';
                    }
                    ans[1][now] = '-';
                    for (int i = sum + 1; i < n; i++)
                        ans[i][now] = '|';
                    ans[n][now] = 'J';
                    out();
                }
            }
        }
    }
}
signed main()
{
    // IOS;
    cin >> _;
    while (_--)
        solve();
}