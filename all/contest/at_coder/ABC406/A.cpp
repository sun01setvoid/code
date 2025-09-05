#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (c<a) cout<<"Yes";
    else if (c>a) cout<<"No";
    else if (c==a){
        if (d<b) cout<<"Yes";
        else if (d>b) cout<<"No";
    }
}