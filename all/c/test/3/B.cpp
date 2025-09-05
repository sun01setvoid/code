#include <iostream>
using namespace std;
int main(){
    int n,t;
    long long temp;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;
        long long sum1=0,sum2=0,sum=0,cnt1=0,cnt2=0;
        for (int j=0;j<n;j++){
            cin>>temp;
            if (j%2==0)
                sum1+=temp,cnt1++;
            else if (j%2==1)
                sum2+=temp,cnt2++;
        }
        if (sum1%cnt1==0 && sum2%cnt2==0 && sum1/cnt1==sum2/cnt2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}