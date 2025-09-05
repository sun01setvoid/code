#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
    int t;
    cin>>t;
    int n,k;
    int l,r;
    while (t--){
        cin>>n>>k;
        for (int i=1;i<=n;i++)  cin>>a[i];
        sort(a+1,a+n+1);
        if (n%2==1){
            l=r=n/2+1;
            if (k%2==1) k++;
            l=max(1,l-k/2);
            r=min(n,r+k/2);
            cout<<a[r]-a[l]+1<<"\n";
        }
        if (n%2==0){
            l=n/2,r=n/2+1;
            l=max(1,l-k/2);
            r=min(n,r+k/2);
            cout<<a[r]-a[l]+1<<"\n";
        }
    }
}