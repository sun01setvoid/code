//lg P10447
#include <iostream>
using namespace std;
int g[25][25];
int main(){
    int n,temp;
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>temp;
            g[i][temp]=1;
        }
    }
    
}