
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
const int maxn = 100;
const int maxm = 3e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;
//-----------------------------------------------------//
// void op(int &a, int &b, int &c, int &d)
// {
//     if (a > b)
//         swap(a, b);
//     if (b > c)
//         swap(b, c);
//     if (c > d)
//         swap(c, d);
//     if (a > b)
//         swap(a, b);
//     if (b > c)
//         swap(b, c);
//     if (a > b)
//         swap(a, b);
// }
// int vis[maxn][maxn][maxn][maxn];
// int sg(int a, int b, int c, int d)
// {
//     if (a == 0 && b == 0 && c == 0 && d == 0)
//         return 0;
//     if (vis[a][b][c][d] != -1)
//         return vis[a][b][c][d];
//     int na, nb, nc, nd;
//     int t;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 0; j <= a - i; j++)
//         {
//             na = a - i - j, nb = b + j, nc = c, nd = d;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//             na = a - i - j, nb = b, nc = c + j, nd = d;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//             na = a - i - j, nb = b, nc = c, nd = d + j;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//         }
//     }
//     for (int i = 1; i <= b; i++)
//     {
//         for (int j = 0; j <= b - i; j++)
//         {
//             na = a + j, nb = b - i - j, nc = c, nd = d;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//             na = a, nb = b - i - j, nc = c + j, nd = d;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//             na = a, nb = b - i - j, nc = c, nd = d + j;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//         }
//     }
//     for (int i = 1; i <= c; i++)
//     {
//         for (int j = 0; j <= c - i; j++)
//         {
//             na = a, nb = b + j, nc = c - i - j, nd = d;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//             na = a + j, nb = b, nc = c - i - j, nd = d;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//             na = a, nb = b, nc = c - i - j, nd = d + j;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//         }
//     }
//     for (int i = 1; i <= d; i++)
//     {
//         for (int j = 0; j <= d - i; j++)
//         {
//             na = a + j, nb = b, nc = c, nd = d - i - j;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//             na = a, nb = b + j, nc = c, nd = d - i - j;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//             na = a, nb = b, nc = c + j, nd = d - i - j;
//             op(na, nb, nc, nd);
//             t = sg(na, nb, nc, nd);
//             if (!t)
//                 return vis[a][b][c][d] = 1;
//         }
//     }
//     return vis[a][b][c][d] = 0;
// }
// void solve()
// {
//     for (int i = 0; i <= 15; i++)
//     {
//         for (int j = i; j <= 15; j++)
//         {
//             for (int k = j; k <= 15; k++)
//             {
//                 for (int v = k; v <= 15; v++)
//                 {
//                     if (vis[i][j][k][v] == -1)
//                         sg(i, j, k, v);
//                     if (!vis[i][j][k][v])
//                         cout << i << " " << j << " " << k << " " << v << endl;
//                 }
//             }
//         }
//     }
// }

signed main()
{
    // memset(vis, -1, sizeof vis);
    IOS;
    int n;
    while (cin >> n && n)
    {
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        bool f=1;
        for (auto x : mp)
        {
            if (x.se & 1)
            {
                cout << "Win" << endl;
                f=0;
                break;
            }
        }
        if (f) cout << "Lose" << endl;
    }
    return 0;
}