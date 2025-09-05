#include <stdio.h>
unsigned int reverse( unsigned int number ){
    static int k=0;
    static int f=0;
    k++;
    if (number<10){
       return number;
    }
    else{
        if (number%10==0) f++;
        if (k!=f)//看k与f是否相同，决定前导0,double pointer
        printf("%d",number%10);
        reverse(number/10);
    }
}
/*
unsigned int reverse( unsigned int number ){
    static p=1;
    if (number<10)    return number;
    int ans=reverse(number/10);
    p*=10;//叶节点当然没有，在回去的第一个点上更新
    return number%10*p+ans;
}
*/