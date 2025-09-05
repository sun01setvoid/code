#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, m;
int ma = 0;
string s1, s2;
bool cmp(int a, int b)
{
    for (int i = a + ma, j = b + ma; i < m && j < m; i++, j++)
    {
        if (s2[i] != s2[j])
        {
            if (s2[i] != s1[i - ma])
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        ma = 0;
        vector<int> s;
        cin >> n >> m;
        cin >> s1 >> s2;
        for (int i = 0; i < m - n + 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s2[i + j] != s1[j])
                    ma = max(ma, j + 1);
                else
                    break;
            }
        }
        for (int i = 0; i < m - n + 1; i++)
        {
            int j;
            for (j = 0; j < n; j++)
            {
                if (s2[i + j] == s1[j]) break;
            }
            if (ma == j)   s.push_back(i);
        }
        sort(s.begin(), s.end());
        int ans = 0;
        for (int i = s[0]; i < s[0] + n; i++)
        {
            if (s2[i] == '1')
                ans++;
        }
        cout << ans << "\n";
    }
}
//不对，why

/*
#include<bits/stdc++.h>
using namespace std;
int T;
int n, m;
string s, t;
vector<int> bes[100010];
vector<string> ans;
int main(){
    cin >> T;
    while(T--) {
        ans.clear();
        for(int i = 0; i < 100000; i++) bes[i].clear();
        cin >> n >> m;
        cin >> s >> t;
        //n = s.size(); m = t.size();
        for(int i = 0; i <= m - n; i++) {
            int len = 0;
            for(int j = 0; j < n; j++) {
                if(s[j] != t[i+j]) len++;
                else break;
            }
            bes[len].push_back(i);
        }
        for(int i = 100000; i >= 0; i--) {
            if(bes[i].size() > 0) {
                for(auto p: bes[i]) {
                    string new_s;
                    for(int k = 0; k < n; k++) {
                        new_s.push_back(((s[k]-'0')^(t[p+k]-'0'))+'0');
                    }
                    ans.push_back(new_s);
                }
                break;
            }
        }
        sort(ans.begin(), ans.end());
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(ans[ans.size()-1][i] == '1') cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
*/