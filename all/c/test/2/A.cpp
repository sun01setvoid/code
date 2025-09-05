#include <iostream>
#include <algorithm>
using namespace std;
int a[60];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int t,n,k,cnt;
    cin>>t;
    for (int i=0;i<t;i++){
        cnt=0;
        cin>>n>>k;
        for (int j=1;j<=n;j++){
            cin>>a[j];
        }
        sort(a+1,a+n+1,cmp);
        for (int j=1;j<=n;j++){
            if (cnt+a[j]>k){
                break;
            }
            cnt+=a[j];
        }
        cout<<k-cnt<<endl;
    }
}