#include <iostream>
#include <algorithm>
using namespace std;
const int N =2e5+10;
typedef long long LL;
LL sum[N][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    int n;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> n;
        cin >> s;
        LL ans = 0;
        if (s[0] == '0')
        {
            sum[0][0] = 0;
            sum[0][1] = 0;
            sum[0][2] = n - 1;
            ans = n - 1;
        }
        else
        {
            sum[0][0] = 0;
            sum[0][1] = 1;
            sum[0][2] = 0;
            ans = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (s[i - 1] == '0')
                {
                    sum[i][0] = i + sum[i - 1][0];
                    sum[i][1] = 0;
                    sum[i][2] = n - i - 1 + sum[i - 1][2];
                    ans = max({ans, sum[i][0], sum[i][1], sum[i][2]});
                }
                else
                {
                    sum[i][0] = i + sum[i - 1][1];
                    sum[i][1] = 0;
                    sum[i][2] = n - i - 1;
                    ans = max({ans, sum[i][0], sum[i][1], sum[i][2]});
                }
            }
            else
            {
                if (s[i - 1] == '0')
                {
                    sum[i][0] = 0;
                    sum[i][1] = 1 + sum[i - 1][2];
                    sum[i][2] = 0;
                    ans = max({ans, sum[i][0], sum[i][1], sum[i][2]});
                }
                else
                {
                    sum[i][0] = 0;
                    sum[i][1] = 1;
                    sum[i][2] = 0;
                    ans = max({ans, sum[i][0], sum[i][1], sum[i][2]});
                }
            }
        }
        cout << ans << "\n";
    }
}