#include <bits/stdc++.h>
using namespace std;
unsigned long long p[20];
signed main(){
    int n,k;
    cin>>n>>k;
    __int128_t mul=1;
    p[0]=1;
    for (int i=1;i<=k;i++){
        p[i]=p[i-1]*10;
    }
    while (n--){
        unsigned long long x;
        cin>>x;
        mul=mul*x;
        if (mul>=p[k]) mul=1;
    }
    cout<<(unsigned long long)mul;
}