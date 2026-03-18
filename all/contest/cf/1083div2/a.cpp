#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<"="<<x<<endl
int main(){
    int t=1;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        int id;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            if (a[i]==n) id=i;
        }
        swap(a[1],a[id]);
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}