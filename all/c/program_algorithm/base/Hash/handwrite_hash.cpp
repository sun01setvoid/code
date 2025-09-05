#include <iostream>
using namespace std;
#define MAX 50021
int f[MAX],g[MAX];
//开放寻址
int hash(int k){
    int t=(k%MAX+MAX)%MAX;
    while (f[t]!=0 && g[t]!=k){//一个判断有没有数，一个判断是不是它
        t=(t+1)%MAX;
    }
    return t;//也可以直接在这里处理hash表，看习惯
}//找到空位或者这个点
//hash后f[t]++,g[t]=s;
//g[t]记录数值，f[t]记录这个数值有多少个
//如果是单g[]数组，应该把g[]中的值改为-1，因为k可能为0


//拉链法
int h[MAX],e[MAX],ne[MAX],w[MAX],idx=1;//用邻接表
int hash1(int k){
    int t=(k%MAX+MAX)%MAX;
    for (int i=h[t];i;i=ne[i]){
        int j=e[i];
        if (j==k)   w[i]++;return true;//或者说return i;
    }
    e[idx]=k,w[idx]++,ne[idx]=h[t],h[k]=idx++;//或者说return idx 
    return false;//hash中没有，刚加进去
}
//还可以在加一个