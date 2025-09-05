#include <iostream>
using namespace std;
int a[100010],st[100010];
int main(){
    string s;
    int n,m,k,cnt=0,tim=0;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>k>>s;
        if (s=="AC" && !st[k]){
            cnt++;
            st[k]=1;
            tim+=a[k];
        }
        else{
            a[k]+=1;
        }
    }
   cout<<cnt<<" "<<tim;
}