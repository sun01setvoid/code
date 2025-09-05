#include <iostream>
typedef long long LL;
using namespace std;
inline LL read() {
    LL res=0; bool f=0;
    char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) res=res*10+(ch^'0'),ch=getchar();
    return f?-res:res;
}
LL k,b,c,v;
inline LL get(LL l,LL r) {
    if(r<b) return 0;
    return (r-b)/k+1-(l>b?(l-1-b)/k+1:0ll);
    //存在负数取整向0靠近的问题,(l-1-b)在[-k+1,-1]上不对
}
int main() {
    LL t=read();
    while(t--) {
        k=read(),b=read(),c=read(),v=read();
        LL ans=0,now=0;
        for(int i=59;i>=0;i--) {
            LL x=(v>>i)&1,y=(c>>i)&1;
            if(x) {
                ans+=get(now+(y<<i),now+(y<<i)+(1ll<<i)-1);
            }
            now+=((x^y)<<i);
        }
        c^=v;
        ans+=get(c,c);
        printf("%lld\n",ans);
    }
    return 0;
}
