#include <iostream>
#include <algorithm>
using namespace std;
int n,k,m;
int a[15];
int vis[2]={0};
double b[10010];
bool cmp(double x,double y){
    return x>y;
}
int main(){
    cin>>n>>k>>m;
    double temp;
    for (int i=0;i<n;i++){
        vis[0]=0,vis[1]=0;
        temp=0.0;
        for (int j=0;j<k;j++){
            cin>>a[j];
            if (a[j]>a[vis[0]]) vis[0]=j;
            if (a[j]<a[vis[1]]) vis[1]=j;
        }
        for (int j=0;j<k;j++){
            if (j!=vis[0] && j!=vis[1]){
                temp+=(double)a[j];
            }
        }
        b[i]=temp/(k-2);
    }
    sort(b,b+n,cmp);
    printf("%.3f",b[2]);
    for (int i=1;i>=0;i--)    printf(" %.3f",b[i]);
}