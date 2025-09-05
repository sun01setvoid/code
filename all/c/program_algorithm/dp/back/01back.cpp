#include <iostream>
#include <cstring>
using namespace std;
int N,C;
int w[1010],c[1010];
int dp[1010];
int main(){
  	int t=1;
  	cin>>t;
    while (t--){
    cin>>N>>C;
    memset(dp,0,sizeof dp);
    for (int i=1;i<=N;i++){
        cin>>w[i];
    }
    for (int i=1;i<=N;i++){
        cin>>c[i];
    }
    for (int i=1;i<=N;i++)
        for (int j=C-c[i];j>=0;j--){
           dp[j+c[i]]=max(dp[j+c[i]],dp[j]+w[i]);
        }
    cout<<dp[C]<<endl;
    }
}