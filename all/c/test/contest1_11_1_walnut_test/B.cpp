#include <iostream>
using namespace std;
int main(){
    int n;
    double a[100],b[100];
    double ans=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
      for (int i=0;i<n;i++){
        cin>>b[i];
        ans+=a[i]*b[i];
    }
    cout<<ans;
    
}