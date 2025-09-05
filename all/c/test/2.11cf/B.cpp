
#include <iostream>
#include <cstring>
using namespace std;
int st[2020];
int main(){
    int t,n;
    int temp;
    cin>>t;
    while (t--){
        memset(st,0,sizeof st);
        cin>>n;
        for  (int i=1;i<=n;i++){
            cin>>temp;
            st[temp]++;
        }
        int flag=1;
        for (int i=1;i<=2010;i++){
            if (st[i]>2){
                st[i+1]+=st[i]-2;st[i]=2;
            }
            if (st[i]==1)  {flag=0;break;}
        }
        if (flag)   cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}