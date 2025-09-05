#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N=200010;
int a[N];
signed main(){
    int n,c;
    cin>>n>>c;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    //考虑双指针牵制，都只会往一个方向走(方向不一定一样)
    //牵扯关系A=B+C,同向移动
    for (int i2=1,i1=1,j1=1,j2=1;i2<=n;i2++,i1=i2){
        while (i2<n && a[i2+1]==a[i1]) i2++;
        for (;j2<i1;){
            while (j2<n && a[j2+1]==a[j1]) j2++;
            if (a[i1]-a[j2]>c) j2++,j1=j2;
            else if (a[i1]-a[j2]==c) ans+=(i2-i1+1)*(j2-j1+1),j2++,j1=j2;
            else break;
        }
    }
    cout<<ans<<"\n";
}