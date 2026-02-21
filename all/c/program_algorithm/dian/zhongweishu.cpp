#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
#define fi first
#define se second
#define pa pair<int, int>
#define vii vector<int>
#define pb push_back
#define debug(x) cerr << #x << '=' << (x) << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
const int z = 2e5 + 10;
const int zz = 2e5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const ld pi = 4. * atan(1.);
const ld eps = 1e-9;
int a[maxn];
int n, k;
//滑动窗口维护中位数
void solve()
{
  multiset<int> s1, s2;
  int sm1 = 0, sm2 = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i], a[i] -= i;
  int ans = 0;
  for (int i = 1, j = 1; j <= n; j++)
  {
    if (!s1.size())
      s1.insert(a[j]), sm1 += a[j];
    else
    {
      if (*s1.rbegin() >= a[j])
        s1.insert(a[j]), sm1 += a[j];
      else
        s2.insert(a[j]), sm2 += a[j];
    }
    int d = s1.size() - s2.size();
    if (d == 2)
    {
      sm1 -= *s1.rbegin();
      sm2 += *s1.rbegin();
      s2.insert(*s1.rbegin());
      s1.erase(prev(s1.end()));
    }
    else if (d == -1)
    {
      sm1 += *s2.begin();
      sm2 -= *s2.begin();
      s1.insert(*s2.begin());
      s2.erase(s2.begin());
    }
    int sm = *s1.rbegin() * s1.size() - sm1 + sm2 - *s1.rbegin() * s2.size();
    // debug(i);debug(j);
    while (sm > k)
    {
      if (*s1.rbegin() >= a[i])
      {
        s1.erase(s1.find(a[i]));
        sm1 -= a[i];
      }
      else
      {
        s2.erase(s2.find(a[i]));
        sm2 -= a[i];
      }
      int d = s1.size() - s2.size();
      if (d == 2)
      {
        sm1 -= *s1.rbegin();
        sm2 += *s1.rbegin();
        s2.insert(*s1.rbegin());
        s1.erase(prev(s1.end()));
      }
      else if (d == -1)
      {
        sm1 += *s2.begin();
        sm2 -= *s2.begin();
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
      }
      sm = *s1.rbegin() * s1.size() - sm1 + sm2 - *s1.rbegin() * s2.size();
      i++;
    }
    ans = max(j - i + 1, ans);
  }
  cout << ans << endl;
}
signed main()
{
  IOS;
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}