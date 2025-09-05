#include <iostream>
#include <map>
using namespace std;
int a[60],b[60];
int main(){
    int t,n;
    int cnta,cntb;
    cin>>t;
    while (t--){
        map <int,int> S1;
        map <int,int> S2;
        cnta=0,cntb=0;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a[i];
            if (!S1.count(a[i]))    cnta++,S1[a[i]]=1;
            else S1[a[i]]+=1;
            
        }
        for (int i=0;i<n;i++){
            cin>>b[i];
            if (!S2.count(b[i])) cntb++,S2[b[i]]=1;
            else S2[b[i]]+=1;
        }
        if (cnta+cntb>=4)   cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
}