#include <iostream>
using namespace std;
template <typename T>
T mymax(T a,T b){
    return a>b?a:b;
}
template <typename T>
T mymin(T a,T b){
    return a<b?a:b;
}
template <typename T>
T add(T a,T b){
    return a+b;
}
template <typename T>
T sub(T a,T b){
    return a-b;
}
template <typename T>
T mul(T a,T b){
    return a*b;
}
template <typename T>
T di(T a,T b){
    return a/b;
}
int main(){
    int a,b;
    double c,d;
    cin>>a>>b; 
    cin>>c>>d;
    cout<<mymax(a,b)<<" ";
    cout<<mymin(a,b)<<" ";
    cout<<add(a,b)<<" ";
    cout<<sub(a,b)<<" ";
    cout<<mul(a,b)<<" ";
    cout<<di(a,b);
    cout<<"\n";
    cout<<mymax(c,d)<<" ";
    cout<<mymin(c,d)<<" ";                           
    cout<<add(c,d)<<" ";
    cout<<sub(c,d)<<" ";
    cout<<mul(c,d)<<" ";
    cout<<di(c,d)<<     "\n";
}