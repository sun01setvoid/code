#include <iostream>
using namespace std;
int cnt[2];
int main(){
    int n;
    int t=1;
    cin>>t;
    string a,b;
    while (t--){
        cin>>n;
        cnt[0]=cnt[1]=0;
        cin>>a>>b;
        for (int i=0;i<=n-1;i++){
            if (a[i]=='0'&& i%2==0) cnt[1]++;
            else if (a[i]=='0' && i%2==1)   cnt[0]++;
        }
        for (int i=0;i<=n-1;i++){
            if (b[i]=='0'&& i%2==0) cnt[0]++;
            else if (b[i]=='0' && i%2==1)   cnt[1]++;
        }
        int ans1=n/2,ans2=(n+1)/2;
        if (cnt[0]>=ans1 && cnt[1]>=ans2)   cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}