#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n;
    ll a,b,c;
    cin>>t;
    ll ans;
    while (t--){
        cin>>n;
        unordered_map  <ll,int> mp;
        for (int i=1;i<=n;i++){
            unordered_map <ll,int> vis;
            cin>>a>>b>>c;
            if ((a-b)%c==0 && !vis[abs((a-b)/c)]) {
                vis[abs((a-b)/c)]=1;
                mp[abs((a-b)/c)]++;
                if (mp[abs((a-b)/c)]==n)    ans=abs((a-b)/c);
            }
            if ((b-c)%a==0 && !vis[abs((b-c)/a)]){
                vis[abs((b-c)/a)]=1;
                mp[abs((b-c)/a)]++;
                if (mp[abs((b-c)/a)]==n)    ans=abs((b-c)/a);
            }
            if ((a-c)%b==0 && !vis[abs((a-c)/b)]){
                vis[abs((a-c)/b)]=1;
                mp[abs((a-c)/b)]++;
                if (mp[abs((a-c)/b)]==n)    ans=abs((a-c)/b);
            }
        }
        cout<<ans<<endl;
    }
}