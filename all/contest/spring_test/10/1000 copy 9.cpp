// 1009存储字符串 hash
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e6 + 10, p = 131;
int primes[N], cnt = 0, st[N], ord[N], P[N];
void isp(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            ord[i] = cnt, primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    isp(1e6);
    P[0] = 1;
    for (int i = 1; i < 1e5; i++)
        P[i] = P[i - 1] * p;
    cin >> t;
    while (t--)
    {
        map<ULL, int> h;
        h[0] = 0;
        int n;
        cin >> n;
        int ma = 0, id = 0;
        set<int> st;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            int x = a[i];
            for (int j = 2; j <= x / j; j++)
            {
                if (x % j == 0)
                {
                    int s = 0;
                    while (x % j == 0)
                        x /= j, s++;
                    if (s & 1)
                    {
                        if (st.count(j))
                            st.erase(j);
                        else
                            st.insert(j);
                    }
                }
            }
            if (x > 1)
            {
                if (st.count(x))
                    st.erase(x);
                else
                    st.insert(x);
            }
            ULL tmp = 0;
            for (auto it = st.begin(); it != st.end(); it++)
            {
                tmp += P[ord[*it]];
            }
            if (!h.count(tmp))
                h[tmp] = i;
            else
            {
                if (ma < i - h[tmp])
                {
                    ma = i - h[tmp];
                    id = h[tmp];
                }
            }
        }
        if (ma == 0)
            cout << -1 << " " << -1 << "\n";
        else
            cout << id + 1 << " " << id + ma << "\n";
    }
}