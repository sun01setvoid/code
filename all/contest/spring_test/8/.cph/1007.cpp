#include <iostream>
#include <unordered_map>
using namespace std;
#define int long long
signed main(){
    int t;
    int n1,n2;
    int a,b;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while (t--){
        unordered_map <int,int> mp;
        cin>>n1>>n2;
        int cnt1=0,cnt2=0;
        int ans=0;
        for (int i=1;i<=n1;i++){
            cin>>a>>b;
            if (i==n1) continue;
            if (b==1)  cnt1+=a*18432,mp[cnt1]=1;
            else if (b==2) cnt1+=a*9216,mp[cnt1]=1;
            else if (b==3) cnt1+=a*6144,mp[cnt1]=1;
            else if (b==4) cnt1+=a*4608,mp[cnt1]=1;
            else if (b==6)  cnt1+=a*3072,mp[cnt1]=1;
            else if (b==8)  cnt1+=a*2304,mp[cnt1]=1;
            else cnt1+=a*1152,mp[cnt1]=1;
        }
        for (int i=1;i<=n2;i++){
            cin>>a>>b;
            if (i==n2) continue;
            if (b==1)  cnt2+=a*18432;
            else if (b==2) cnt2+=a*9216;
            else if (b==3) cnt2+=a*6144;
            else if (b==4) cnt2+=a*4608;
            else if (b==6)  cnt2+=a*3072;
            else if (b==8)  cnt2+=a*2304;
            else cnt2+=a*1152;
            if (mp.count(cnt2)) ans++;
        }
        cout<<ans+1<<"\n";
    }
}