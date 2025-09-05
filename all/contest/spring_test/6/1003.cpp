#include <iostream>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int a[N],b[N],c[N];
int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++)  cin>>a[i];
        for (int i=1;i<=n;i++)  cin>>b[i],c[i]=a[i]+b[i];
        LL sum=0,ma=0;
        int l=1,r=0;
        c[0]=c[1];

        for (int i=1;i<=n;i++){
            if(c[i]==c[i-1])    sum+=a[i],r++; 
            else{
                ma=max(sum*(r-l+1),ma);
                sum=a[i];
                l=r=i;
            }
        }
        ma=max(sum*(r-l+1),ma);
        cout<<ma<<endl;
    }
}