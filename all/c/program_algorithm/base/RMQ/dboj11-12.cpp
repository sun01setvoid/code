#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a[1010];
int st[1010][11];
int main(){
    int t,n,q,l,r;
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++)   cin>>a[i];
        for (int i=1;i<=n;i++)  st[i][0]=a[i];
        for (int i=1;i<=9;i++){//区间大小
            for (int j=1;j<=n-(1<<i)+1;j++){
              	int k=1<<i-1;
                st[j][i]=max(st[j][i-1],st[j+k][i-1]);
            }
        }
        cin>>q;
        for (int i=0;i<q;i++){
            cin>>l>>r;
            int k=log2(r-l+1);
            int m=1<<k;
            cout<<max(st[l][k],st[r-m+1][k])<<endl;
        }
    }
}