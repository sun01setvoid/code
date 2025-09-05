#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[9],i=0;
    int ans[3],cnt=0,num=0,p=1;
    int temp;
    cin>>temp;
    while(temp!=0){
        a[i++]=temp%10;
        temp/=10;
        cnt++;
    }
    sort(a,a+cnt);
    num=cnt/3;
    for (int i=0;i<cnt;i++){
        ans[num]=a[i]*p+ans[num];
    }

}