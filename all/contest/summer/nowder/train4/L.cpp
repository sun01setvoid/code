#include<iostream>
#include <algorithm>
#define F first
#define S second
using namespace std;
typedef pair<int, int>pi;
const int B = 30;
const int U = 1 << B;
const int maxn = 2e5 + 10;
int a[maxn], n, q;
pi f[maxn][16];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n - B + 1;i++) {
        int cur = 0, r = 0;
        for (int j = 0;j < B;j++) {
            if ((cur + a[i + j]) & 1) r |= 1 << j, cur++;
            cur = (cur + a[i + j]) / 2;
        }
        f[i][0] = { cur,r };
    }
    //一定有进位，不管B开多大，他都有可能有进位，因为C也是指数级增加的
    for (int j=1;j<=14;j++)
        for (int i=1;i<=n-(B<<j)+1;i++){
            int res=f[i+(B<<(j-1))][j-1].F;
            if (f[i][j-1].F==f[i+(B<<(j-1))][j-1].S){
                f[i][j]={res,f[i][j-1].S};
            } else if (f[i][j-1].F<f[i+(B<<(j-1))][j-1].S){
                f[i][j]={res,U};//U是不可能加1
            } else {
                f[i][j]={res+1,U};
            }
        }
    while (q--){
        int s,t,x,y; cin >> s >> y; y=n-y+1; y++;
        x=upper_bound(a+1,a+n+1,s)-a;
        if (x>=y){
            cout << 0 << endl;
            continue;
        }
        t=s;
        while ((y-x)%B) t=(t+a[x]+1)/2,x++;
        int st=(y-x)/B;
        for (int i=0;i<=14;i++) if ((st>>i)&1){
            t=f[x][i].F+(t>f[x][i].S);
            x+=B<<i;
        }
        cout << t-s << endl;
    }
}