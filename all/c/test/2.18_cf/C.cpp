#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll m=998244353;
//最好不要减，可能有负数,要取模
int main(){
    int t;
    cin>>t;
    int n;
    int temp;
    while (t--){
        cin>>n;
        vector <ll> dp(4,0);
        for (int i=1;i<=n;i++){
            cin>>temp;
            if (temp==1)    dp[1]=(dp[1]+1)%m;
            if (temp==2)    dp[2]=(dp[2]*2+dp[1])%m;
            if (temp==3){
                dp[3]=(dp[2]+dp[3])%m;
            }
        }
        cout<<dp[3]<<endl;
    }
}