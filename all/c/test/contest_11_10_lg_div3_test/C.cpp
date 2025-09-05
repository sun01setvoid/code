#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct sol {
    long long ai;
    int x;
}a[200000];
int st[200000];
bool cmp(sol a,sol b){
    return a.ai<b.ai;
}
int main(){
    int n,k,amin,l,r;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i].x=i;
    }
    sort(a,a+n,cmp);
    bool flag;
    do{
        flag=0;
        int i;
        for (i=0;i<n-1;i++){
            l=i;
            while ( i<n-1 && a[i].ai==a[i+1].ai) {
                i++;
            }
            r=i;
            if (i==n-1){
                for (int j=l;j<=r-1;j++)
                a[j].ai+=k;
                break;
            }
            if (a[i].ai+k<a[i+1].ai){
                for (int j=l;j<=r;j++){
                    a[j].ai+=k;
                }
            }
            else{
                for (int j=l;j<=r;j++)  st[a[j].x]+=1;
                flag=1;
            }
        }
        a[n-1].ai+=k;
    }
    while (flag);
    for (int i=0;i<n;i++){
        cout<<st[i]<<" ";
    }
    system("pause");
}