//P1883洛谷
//三分
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10010],b[10010],c[10010];
double f(double x,int i){
  return a[i]*x*x+b[i]*x+c[i];
}
int main(){
  int t,n;
  scanf("%d",&t);
  for (int i=0;i<t;i++){
    scanf("%d",&n);
    double ans1,ans2;
    for  (int j=0;j<n;j++){
      scanf("%d %d %d",&a[j],&b[j],&c[j]);
    }
    double l=0,r=1000,mid1,mid2;
    while (r-l>1e-9){
        mid1=l+(r-l)/3,mid2=r-(r-l)/3;
        ans1=f(mid1,0),ans2=f(mid2,0);
        for (int j=1;j<n;j++){
          ans1=max(ans1,f(mid1,j)),ans2=max(ans2,f(mid2,j));
        }
        if (ans1>ans2)
            l=mid1;
        else 
            r=mid2;
    }
    ans1=f(l,0);
    for (int j=1;j<n;j++){
        ans1=max(ans1,f(l,j));
    }
    printf("%.4f\n",ans1);
  }
}