#include <iostream>
#include <unordered_map>
//gcd
using namespace std;
typedef long long ll;
int gcd(int x ,int y){
    int z=x%y;
    while (z){
        x=y;
        y=z;
        z=x%y;
    }
    return y;
}
int main(){
//预处理x**n,在set或者map里寻找;对那些不是按序的查找来说很好用，当然也可以用二分这里
    ll mul=1;
    unordered_map <int,int> S6;
    unordered_map <int,int> S5;
    for (int i=0;mul<=1e9+1;i++){
        S6[mul]=i;
        mul*=6;
    }
    mul=1;
    for (int i=0;mul<=1e9+1;i++){
        S5[mul]=i;
        mul*=5;
    }
    int t;
    cin>>t;
    int x,y;
    for (int i=0;i<t;i++){
        cin>>x>>y;
        int mid=gcd(x,y);
        if (S6.count(x/mid) && S5.count(y/mid)){//与最大公约数的商是6的n次或者是5的n次
            cout<<S6[x/mid]+S5[y/mid]<<endl;
        }
        else
        cout<<-1<<endl;

    }
}