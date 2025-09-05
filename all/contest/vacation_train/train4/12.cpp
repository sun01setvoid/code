#include <iostream>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a[1010],stk[1010],top=-1;
    while (k--){
        for (int j=1;j<=n;j++){
            cin>>a[j];
        }
        int cur=1,i=1;
        while (cur<n){
            bool f=0;
            while (top!=-1 && stk[top]==cur){
                top--,cur++;
                f=1;
            }
            if (i<=n && a[i]==cur)    i++,cur++,f=1;
            else if (i<=n && a[i]!=cur){
                if (top<m-1)    stk[++top]=a[i],f=1,i++;
                else {
                    cout<<"NO"<<endl;break;
                }
            }
            if (!f)    {cout<<"NO"<<endl;break;}
        }
        if (cur==n)
            cout<<"YES"<<endl;
    }
}