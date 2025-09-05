#include <bits/stdc++.h>
using namespace std;
#define t1 cout<<"Flower"<<endl;
#define t2 cout<<"Gellyfish"<<endl;
int main(){
    int _;
    cin>>_;
    while (_--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (b<=a && b<=c ) t2
        else if (a<d) t1
        else if (d<=c) t2
        else t1
    }
}