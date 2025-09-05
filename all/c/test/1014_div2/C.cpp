#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL odd[N];
int main(){
    int t=1,n;
    LL tmp;
    cin>>t;
    while (t--){
        cin>>n;
        LL ma=0;
        int cnt=0;
        LL sum=0;
        for (int i=1;i<=n;i++){
            cin>>tmp;
            ma=max(tmp,ma);
            if (tmp%2==1)   {
                odd[++cnt]=tmp;
            }
            else sum+=tmp;
        }
        if (cnt==0 || sum==0) cout<<ma<<endl;
        else{
            for (int i=1;i<=cnt;i++){
                sum+=odd[i]-1;
            }
            cout<<sum+1<<endl;
        }
    }
}