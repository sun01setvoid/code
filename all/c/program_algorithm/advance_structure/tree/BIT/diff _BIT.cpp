#include <iostream>
#include <cstring>
using namespace std;
const int N=1e6+10;
int n;
int tr[N];
int lowbit(int x){
    return x&-x;
}
void update(int x,int c){
    for (int i=x;i<=n;i+=lowbit(i))     tr[i]+=c;
}
int sum(int x){
    int res=0;
    for (int i=x;i;i-=lowbit(i))    res+=tr[i];
    return res;    
}
int main(){
    int a,b;
    while (cin>>n && n){
        memset(tr,0,sizeof tr);
        for (int i=1;i<=n;i++){
            cin>>a>>b;
            update(a,1);
            update(b+1,-1);
        }
      	cout<<sum(1);
        for (int i=2;i<=n;i++){
            cout<<" "<<sum(i);
        }
        cout<<endl;
    }
}