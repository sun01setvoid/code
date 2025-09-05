#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int cnt,sum;
};
node dp1[26];
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        memset(dp1, 0, sizeof(dp1));
        int n = s.size();
        int ans = 0;
        for (int i = 1; i <=n; i++)
        {
            if (dp1[s[i-1]-'A'].cnt != 0){
                ans+=dp1[s[i-1]-'A'].cnt*(i-1)-dp1[s[i-1]-'A'].sum;
            }
            dp1[s[i-1] - 'A'].sum += i;
            dp1[s[i-1] - 'A'].cnt++;
        }
        cout << ans << endl;
    }
}