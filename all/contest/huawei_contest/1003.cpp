#include <bits/stdc++.h>
using namespace std;
#define int long long
stack<int> st;
string s;
int n;
bool dp(int pos)
{
    if (pos == n)
        return 0;
    int val = s[pos] - '0';
    bool flag = 0;
    if (st.size() && st.top() == val)
    {
        st.pop();
        flag = 1;
    }
    else
        st.push(val);
    if (dp(pos + 1))
        return 1;
    if (flag)
        st.push(val);
    else
        st.pop();
    for (int w = val - 1; w >= ((pos == 0) ? 1 : 0); w--)
    {
        int siz = st.size();
        if (st.size() && w == st.top())
            siz--;
        else
            siz++;
        if (n - pos - 1 - siz >= 0 && (n - pos - 1 - siz) % 2 == 0)
        {
            for (int i = 0; i < pos; i++)
                cout << s[i];
            char c = '0' + w;
            cout << c;
            if (st.size() && st.top() == w)
                st.pop();
            else
                st.push(w);
            for (int i = 0; i < (n - pos - 1 - siz); i++)
                cout << "9";
            while (st.size())
            {
                c = st.top() + '0';
                cout << c;
                st.pop();
            }
            cout << endl;
            return 1;
        }
    }
    return 0;
}
void solve()
{
    cin >> s;
    n = s.size();
    while (st.size())
        st.pop();
    for (int i = 0; i < s.size(); i++)
    {
        int val = s[i] - '0';
        if (st.size() && val == st.top())
            st.pop();
        else
            st.push(val);
    }
    if (st.empty())
    {
        cout << s << endl;
        return;
    }
    while (st.size())
        st.pop();
    if (dp(0))
        return;
    int siz = ((n - 1) & 1) ? n - 2 : n - 1;
    for (int i = 0; i < siz; i++)
        cout << "9";
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}