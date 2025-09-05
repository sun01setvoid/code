/*
#include <iostream>
using namespace std;
long long fpow(int a,int b,int c){
    long long ans=1;
    if (b==1)   return a;
    else{
        ans = (fpow(a,b/2,c)%c*(fpow(a,b/2,c)%c))%c;//there is tree here,2**logn,just n
        if (b%2==1) ans=(ans*a)%c;
        return ans;
    }
}
int main(){
    int n,a,b,c;
    cin>>n;
    while (n--){
        cin>>a>>b>>c;
        cout<<fpow(a,b,c)<<endl;
    }
    system("pasuse");
}
*/
#include <iostream>
using namespace std;
typedef long long ll;

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
int main()
{
    int n;
    scanf("%d", &n);
    int a, k, p;
    while (n--)
    {
        cin >> a >> k >> p;
        cout << fpow(a, k, p) << endl;
    }
}
/*
#include <iostream>
using namespace std;
typedef long long ll;
ll fpow(int a,int k,int p){
    int ans;
    if (k==0)   ans=1;
    else{
        ans=fpow(a*a,k>>1,p)//k二进制表示，先把底全都给他
        if (k&1)    ans*=a;//1101，1->1->0->1;
    }
    return ans;//相当于先到底，再处理吧
}
*/