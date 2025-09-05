#include <iostream>
using namespace std;
int a[1010];
int main(){
    int t,n,temp,cnt1,cnt2,m;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;
        cnt1=0,cnt2=0,m=0;
        for (int j=1;j<=n;j++){
            a[j]=0;
        }
        for (int j=1;j<=n;j++){
            cin>>temp;
            a[temp]+=1;
        }
        for (int j=1;j<=n;j++){
            if (a[j]==1)  cnt1++;

            else if (a[j]>1) cnt2++;
        }
        m=(cnt1+1)/2*2;
        cout<<m+cnt2<<endl;
    }
}        
