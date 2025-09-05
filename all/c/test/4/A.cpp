#include <iostream>
#include <cmath>
using namespace std;
int a[110];
int main(){
    int n,k,t,ans;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n>>k;
        for (int j=0;j<n;j++)
            cin>>a[j];
        int flag=0;
        for (int j=0;j<n;j++){
            int st=0;
            for (int v=0;v<n;v++)
                if (j!=v && abs(a[v]-a[j])%k==0)
                    {st=1;break;}
            if (!st)   {ans=j+1;flag=1;break;}
        }
        if (flag){
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
        else 
            cout<<"NO"<<endl;
    }
}