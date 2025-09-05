#include <iostream>
using namespace std;
long long inf=1e9+7;
long long dp1[110],dp2[110];
int main(){
    int t,n,m,a,b;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n>>m;
        for (int j=1;j<=n;j++){
            dp1[j]=0;
            dp2[j]=0;
        }
        for (int j=1;j<=m;j++){
            cin>>a>>b;
            if (a==1)
                dp1[b]+=1;
            else if(a==2)
                dp2[b]+=1;
        }
        long long cnt1=0,k2=0,cnt2=0,ins=0;
        int st1=n+1,st2=n+1;
        for (int j=1;j<=n;j++){
            if (dp1[j]!=0){
                st1=j;
                break;
            }
        }
        for (int j=1;j<=n;j++){
            if (dp2[j]!=0){
                st2=j;
                break;
            }
        }
        for (int j=st1;j<=n;j++){
            if (dp1[j]!=0)  {cnt1+=dp1[j];}
                dp1[j]=(dp1[j-1]+cnt1)%inf;
        }
        for (int j=st2;j<=n;j++){
            if (dp2[j]!=0){
                cnt2+=dp2[j],ins+=dp2[j];
            }
            dp2[j]=(dp2[j-1]+2*k2+cnt2)%inf;
            k2+=ins;
        }
        for (int j=1;j<=n;j++){
            cout<<(dp1[j]+dp2[j])%inf<<endl;
        }
    }
}