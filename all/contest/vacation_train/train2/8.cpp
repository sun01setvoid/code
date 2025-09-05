#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,temp;
    int ma=0,mi=1000010,cnt1=0,cnt2=0;
    cin>>n;
    while (n--){
        cin>>temp;
        if (temp>ma)    ma=temp,cnt1=1;
        else if (temp==ma)    cnt1++;
        if (temp<mi)    mi=temp,cnt2=1;
        else if (temp=mi)    cnt2++;
    }
    printf("%d %d\n%d %d",mi,cnt2,ma,cnt1);
}