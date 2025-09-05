#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'
#define debug(x) cerr << #x << '=' << (x) << endl
#define fi first
#define so second
#define int long long
#define vii vector<int>
#define pii pair<int, int>
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10;
const int maxm = 6e1 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-10;
//-----------------------------------------------------//
struct oo
{
    int h, w;
} b[maxn];
int n, m, x, y, a[maxn], aa[maxn];
void output(double x)
{
    static char s[25];
    sprintf(s, "%.4le", x);
    for (int i : {0, 1, 2, 3, 4, 5, 6, 7})
        printf("%c", s[i]);
    printf("%c", s[strlen(s) - 1]);
    printf("\n");
}
double fast(double x, int y)
{
    if (y == 0)
        return 1.0;
    double ans = fast(x * x, y / 2);
    if (y & 1)
        ans = (ans * x);
    return ans;
}
double cal(double x1, double y1, double x2, double y2)
{
    double val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return val;
}
double caly(double x)
{
    double ans = 0;
    for (int i = 1; i <= m; i++)
        ans += (double)a[i] * fast(x, i);
    return ans;
}
double k(double x1, double y1, double x2, double y2)
{
    double y = y1 - y2;
    double x = x1 - x2;
    return y / x;
}
double ff(double x){
	double res=0,xx=1;
	for(int i=0;i<=m-1;i++){res+=aa[i]*xx;xx*=x;}
	return sqrtl(res*res+1L);
}
double simpson(double l, double r) {
  double mid = (l + r) / 2;
  return (r - l) * (ff(l) + 4 * ff(mid) + ff(r)) / 6;  // 辛普森公式
}
double asr(double l, double r, double eps, double ans, int step) {
  double mid = (l + r) / 2;
  double fl = simpson(l, mid), fr = simpson(mid, r);
  if (abs(fl + fr - ans) <= 15 * eps && step < 0)
    return fl + fr + (fl + fr - ans) / 15;  // 足够相似的话就直接返回
  return asr(l, mid, eps / 2, fl, step - 1) +
         asr(mid, r, eps / 2, fr, step - 1);  // 否则分割成两段递归求解
}
double calc(double l, double r, double eps) {
  return asr(l, r, eps, simpson(l, r), 4);
}
void Raze()
{
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        aa[i - 1] = i * a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i].h >> b[i].w;
    vii tmp;
    double ans = INF;
    for (int i = 1; i <= n; i++)
        tmp.pb(i);
    do
    {
        double sum = 0.;
        double nx = 0., ny = 0.;
        for (int i = 1; i < n; i++)
        {
            int h = max(b[tmp[i]].h, b[tmp[i - 1]].h);
            double now = 0, pk = k(x, y, nx, ny + b[tmp[i - 1]].h);
            double l = nx + eps, r = (double)1e10;
            while (r - l > eps)
            {
                double mid = (r + l) / 2;
                double cy = caly(mid);
                if (cal(nx, ny, mid, cy) >= (double)h * h && k(x, y, mid, cy) >= pk)
                    r = mid;
                else
                    l = mid;
            }
            double xx = (l + r) / 2;
            double yy = caly(xx);
            double dis=calc(0,xx,eps);
            sum = sum + dis * b[tmp[i]].w;
            nx = xx;
            ny = yy;
        }
        ans = min(ans, sum);
    } while (next_permutation(tmp.begin(), tmp.end()));
    output(ans);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        Raze();
    return 0;
}