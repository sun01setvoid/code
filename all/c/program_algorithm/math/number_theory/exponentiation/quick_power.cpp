#include <iostream>
using namespace std;
typedef long long ll;
ll qp(ll a,ll k,ll m){
    ll res=1;
    while (k){
        if (k&1)    res=res*a%m;
        a=a*a%m;
        k/=2;
    }
    return res;
}
/*
ll fpow(int a, int k, int p)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
        {
            res = res * a % p;
        } // 1101,1->0->1->1;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}
*/