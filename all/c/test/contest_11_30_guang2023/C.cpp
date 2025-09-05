#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin>>T;
    long long n;
    for (int i=0;i<T;i++){
        cin>>n;
        if (n>=2)
            cout<<5<<endl;
        else
            cout<<9<<endl;
    }
}
//5的特殊性