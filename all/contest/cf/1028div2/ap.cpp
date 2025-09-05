#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while (_--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a==b){
            if (c<b && d>c) cout<<"Flower"<<endl;
            else cout<<"Gellyfish"<<endl;
        }
        else if (a<b){
            if (d>a || d>c) cout<<"Flower"<<endl;
            else cout<<"Gellyfish"<<endl;
        }
        else{
            if (c<b && d>c) cout<<"Flower"<<endl;
            else cout<<"Gellyfish"<<endl;
        }
    }
}