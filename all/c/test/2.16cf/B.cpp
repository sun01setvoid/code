#include <iostream>
#include <iostream>
using namespace std;
int mp[200010];
int a[200010];
int main(){
    int t;
    cin>>t;
    int n,temp;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++)  mp[i]=0;
        int i,j;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int res=0,ma=0,flag=-1;
        for (int i=1;i<=n;i++){
            if (mp[a[i]]==1)    res++;
            else if (mp[a[i]]!=1 && res){
                if (res>ma) ma=res,flag=i-1;
                res=0;
            }   
        }
        if (mp[a[n]]==1){
            if (res>ma) flag=n,ma=res;
        }
        if (flag==-1)   cout<<0<<endl;
        else    cout<<flag-ma+1<<" "<<flag<<endl;
    }
}