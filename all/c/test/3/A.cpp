#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[100];
int main(){
    string s;
    int t,n,m,temp,cnt;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n>>m;
        cnt=0;
        for (int j=0;j<n;j++){
            cin>>s;
            temp=s.size();
            dp[j]=temp;
        }
        for (int j=0;j<n;j++){
             if (m-dp[j]>=0){
                cnt++;
                m-=dp[j];
            }
            else 
                break;
        }
        cout<<cnt<<endl;
    }

}