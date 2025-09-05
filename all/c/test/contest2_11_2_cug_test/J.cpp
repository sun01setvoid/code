#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct ran{
     double l,r;
};
bool cmp(ran a,ran b){
    return a.l<b.l;
}
int main(){
    struct ran danger[100010];
    long long x0,y0,k,xi,yi,ri,cnt=0;
    double ans=0;
    cin>>x0>>y0>>k;
    for (int i=0;i<k;i++){
        cin>>xi>>yi>>ri;
        if (ri>abs(yi-y0) && xi+sqrt(ri*ri-(yi-y0)*(yi-y0))>x0){
            if (xi-sqrt(ri*ri-(yi-y0)*(yi-y0))>x0)
                danger[cnt].l=xi-sqrt(ri*ri-(yi-y0)*(yi-y0));
            else
                danger[cnt].l=x0;       
            danger[cnt].r=xi+sqrt(ri*ri-(yi-y0)*(yi-y0));
            cnt++;
        }
    }
    sort(danger,danger+cnt,cmp);
    if (cnt==1){
        ans=danger[0].r-danger[0].l;
    }
    for (int i=0,j=1;i<cnt && j<cnt;){
        double ma=danger[i].r;//注意被包含的区间
        while( j!=cnt && danger[j].l<=ma ){
            ma=max(ma,danger[j].r);
            j++;
        }
        ans+=ma-danger[i].l;
        i=j;
        if (i==cnt-1){
            ans+=danger[cnt-1].r-danger[cnt-1].l;
            break;
        }
        j=i+1;
    }
    cout<<ans;
}