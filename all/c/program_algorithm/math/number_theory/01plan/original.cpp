//最大比例算出结余为0,若不是最大比例,用最大比例算出的结余<0,所以最大比例即有最大结余
//于是我们定下一个比例，算出他的最大结余,若大于0，则说明比例过小，若小于0，说明比例过大，所以二分求答案
#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
int a[1010],b[1010];
double p[1010];
bool cmp(double x,double y){
    return x>y;
}
bool check(double x){
    for (int i=1;i<=n;i++)  p[i]=a[i]-x*b[i];
    sort(p+1,p+n+1,cmp);
    double res=0;
    for (int i=1;i<=n-k;i++)    res+=p[i];
    return res<0;    
}
int main(){
    while(cin>>n>>k && (n || k)){
        double l=0,r=0;
        for (int i=1;i<=n;i++)  cin>>a[i],r+=a[i];
        for (int i=1;i<=n;i++)  cin>>b[i];
        for (int i=0;i<50;i++){
            double m=(l+r)/2;
            if (check(m))   r=m;
            else    l=m;
        }
        cout<<(int)(l*100+0.5)<<endl;
    }
}