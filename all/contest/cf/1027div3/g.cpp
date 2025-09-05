#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, k;
int lowbit(int x)
{
    return x & -x;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> a(n + 2,0);
        int ans = 0;
         for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector <int> suf(n+2,0),pre(n+2,0);
        bool f=0;
        for (int i = 2; i <= n; i ++)
        {
            if (a[i-1]%a[i]==0){
                int t=a[i-1]/a[i];
                if (t==lowbit(t)){
                    pre[i]=lowbit(a[i-1])-lowbit(a[i]*2)+1+pre[i-1];
                }
                else pre[i]=pre[i-1]+lowbit(a[i-1]);
            }
            else pre[i]=pre[i-1]+lowbit(a[i-1]);
        }
        for (int i=n-1;i>=1;i--){
            if (a[i+1]%a[i]==0){
                int t=a[i+1]/a[i];
                if (t==lowbit(t)){
                    suf[i]=lowbit(a[i+1])-lowbit(a[i]*2)+1+suf[i+1];
                }
                else suf[i]=lowbit(a[i+1])+suf[i+1];
            }
            else suf[i]=lowbit(a[i+1])+suf[i+1];
        }
        for (int i=1;i<=n;i++){
            ans=max(suf[i]+pre[i]+lowbit(a[i]),ans);
        }
        cout<<(ans>=k?"YES":"NO")<<endl;
    }
}