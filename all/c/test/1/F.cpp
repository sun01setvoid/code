#include <iostream>
using namespace std;
const int N=1e5+10;
long long dp[N];
long long m=1e9+7;
int main(){
    int n;
    string s;
    long long sum=0;
    cin>>n;
    dp[1]=n;
    for (int i=1;i<=n;i++)  cin>>s;
    for (int i=2;i<=n;i++){
        dp[i]=dp[i-1]*(n-i+1)%m;
    }
    for (int i=1;i<=n;i++){
        sum=(sum+dp[i])%m;
    }
    cout<<sum;
}