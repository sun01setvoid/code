#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while (_--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a==c){
            if (d>b) cout<<"Flower"<<endl;
            else cout<<"Gellyfish"<<endl;
        }
        else if (a<c){
            if (d>a || d>b) cout<<"Flower"<<endl;
            else cout<<"Gellyfish"<<endl;
        }
        else{
            if (b<c && d>b) cout<<"Flower"<<endl;
            else cout<<"Gellyfish"<<endl;
        }
    }
}