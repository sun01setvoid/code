#include <iostream>
#include <algorithm>
#include  <cmath>
#include <stdio.h>
using namespace std;
int a[1000010],sum[1000000];
int main(){
    int n,q,l,r,k,ans;
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=q;i++){
        scanf("%d %d %d",&l,&r,&k);
        if (k>=r-l+1){
            cout<<"-1"<<endl;
        }
        else{
            if (k<r-l){
                ans=abs(sum[r]-sum[l-1]-k);
            }
            else {
                ans=min(abs(r-l+1-(sum[r]-sum[l-1])),abs(sum[r]-sum[l-1]-(r-l)));
            }
            cout<<ans<<endl;
        }
    }
    system("pause");
}