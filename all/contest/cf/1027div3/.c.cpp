#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int cnt1=1;
        int ans=0;
        for (int i=1;i<=n-1;i++){
            if (a[i+1]-a[i]<=1) cnt1+=a[i+1]-a[i];
            else if (cnt1%2==0) ans+=cnt1/2,cnt1=1;
            else ans+=(cnt1+1)/2,cnt1=1;
        }
        ans+=(cnt1+1)/2;
        cout<<ans<<endl;
    }
}