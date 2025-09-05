//过于好了，实际上没有重叠
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int a[86410];
int main(){
    int n;
    scanf("%d",&n);
    int h1,m1,s1;
    int h2,m2,s2;
    while (n--){
        scanf("%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int st=h1*60*60+m1*60+s1+1;
        int en=h2*60*60+m2*60+s2;
        a[st]++,a[en+1]--;
    }
    for (int i=1;i<=86400;i++){
        a[i]=a[i-1]+a[i];
    }
    int l=0,r=0;
    //表示从i-1到i时刻这一分钟
    for (int i=1;i<=86399;i++){
        if (i==1 && a[i]==0) l=0,r=l;
        else if (a[i]==0 && a[i-1]==1) l=i-1,r=l;
        else if (a[i]==0 && a[i]==a[i-1])  r++;
        else if (i!=1 && a[i] && a[i-1]==0){
            h1=l/60/60,m1=l/60%60,s1=l%3600%60;
            r+=1;
            h2=r/60/60,m2=r/60%60,s2=r%3600%60;
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
        }
    }
    //缺少1分钟
    if (a[86399]==0){
        h1=l/60/60,m1=l/60%60,s1=l%3600%60;
        r+=1;
        h2=r/60/60,m2=r/60%60,s2=r%3600%60;
        printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
    }
}
