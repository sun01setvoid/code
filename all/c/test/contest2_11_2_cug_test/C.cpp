#include <iostream>
using namespace std;
int main(){
    int n,a[3000],ans=1;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if ((a[i]&a[j])==0){
                ans=0;
                break;}
        }
    }
    if (ans)    cout<<"No";
    else    cout<<"Yes";

}