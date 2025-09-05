#include <iostream>
#include <algorithm>
using namespace std;
long long a[100010];
long long b[100010];
int main(){
    int t;
    int n,l,r,l1,r1;
    cin>>t;
    while(t--){
        long long sum1=0,sum2=0;
        cin>>n>>l>>r;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(a+1,a+r+1);
        sort(b+l,b+n+1);
        int cnt=0;
        for (int i=1;i<=r && cnt<r-l+1;i++){
           sum1+=a[i];
           cnt++;
        }
        cnt=0;
        for (int i=l;i<=n && cnt<r-l+1;i++){
            sum2+=b[i];
            cnt++;
        }
        cout<<min(sum1,sum2)<<endl;
    }
}