#include <iostream>
#include <cstring>
using namespace std;
int q[2700];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n=0,l,m;
    cin>>t;
    string str,p,k;
    while (t--){
        cin>>str>>k;
        if (k.size()<=2){
            m=stoi(k);
        }
        else{
            m=26;
        }
        for (int i=0;i<n;i++)   q[i]=0;
        l=str.size();
        p=str,n=l;
        for (int i=1;i<=m-1 && i<=25;i++){
            p+=str;
            n+=l;
        }
        int len=0;
        for (int i=0;i<n;i++){
            int l=0,r=len;
            q[0]=-2e9;
            while (l<r){
                int mid=(l+r+1)>>1;
                if (q[mid]<p[i])
                    l=mid;
                else r=mid-1;
            }
            q[l+1]=p[i];
            len=max(l+1,len);
        }
        cout<<len<<endl;
    }
}