//完全背包
//求方法数，把价值转换为方法数，开始计算
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int f[20][15];
    int N,V;
    int v,w;
    cin>>N>>V;
    memset(f,-0x3f,sizeof f);
    for (int i=0;i<=N;i++)  f[i][0]=0;
    for (int i=1;i<=N;i++){
        cin>>v>>w;
        for (int j=v;j<=V;j++){
            f[i][j]=max(f[i-1][j],f[i][j-v]+w);//递推j>=v[k]
        }
    }

    for (int i=0;i<=N;i++){
        for (int j=0;j<=V;j++){
            cout<<f[i][j]<< " ";
        }
        cout<<endl;
    }
}