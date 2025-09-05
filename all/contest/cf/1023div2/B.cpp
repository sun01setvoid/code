#include <iostream>
#define int long long 
using namespace std;
signed main(){
    int t;
    cin>>t;
    int n,k;
    while (t--){
        cin>>n>>k;
        int tmp;
        int mi=1e9+1,ma=0;
        int cnt2=0,sum=0;
        for (int i=1;i<=n;i++) {
            cin>>tmp;
            sum+=tmp;
            if (tmp<mi) mi=tmp;
            if (tmp>ma) ma=tmp,cnt2=1;
            else if (tmp==ma) cnt2++;
        }
        if (ma-mi>k+1 || ma-mi>k && cnt2>=2) {
            cout<<"Jerry"<<"\n";
        }
        else {
            if (sum % 2)
            cout<<"Tom"<<"\n";
            else cout<<"Jerry"<<"\n";
        }
    }
}