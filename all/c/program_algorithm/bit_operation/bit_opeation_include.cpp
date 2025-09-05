/*是否是2的幂*/
//lobit(x)==x

/*是否是三的幂*/
//return (n>0 && 1162261467&n==0);3**19,int中最大的3的幂

/*返回>=n,最小的(二的幂)*/
int find(int n){
    if (n<=0){return 1;}
    n--;//防二的幂
    //把位数都刷成1
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;
    return n+1;
}

/*返回 从left开始，到right的所有数的 &*/
int rangeBitwiseAnd(int left,int right){
    while (left<right){
        right-=right&-right;
    }//right最多有32个一
    return right;
}

/*逆序二进制的状态*/
int rerverse(int n){
    //1v1,2v2,4v4,8v8,16v16
    n =((n & 0xaaaaaaaa)>>1)|((n &0x55555555)<<1);
    n =((n & 0xcccccccc)>>2)|((n &0x33333333)<<2);
    n =((n & 0xF0F0F0F0)>>4)|((n &0x0F0F0F0F)<<4);
    n =((n & 0xFF00FF00)>>8)|((n &0x00FF00FF)<<8);
    n =( n >>16)|( n <<16);
    return n;
}

/*返回二进制中有几个1*/
//长度为1的区间有几个1，迁移到长度为2-》为4->32的计数
int find(int n){    //n&(n-1)也是一种简单的方法
    n =((n & 0x55555555))+((n>>1) & 0x55555555);
    n =((n & 0x33333333))+((n>>2) & 0x33333333);
    n =((n & 0x0f0f0f0f))+((n>>4) & 0x0f0f0f0f);
    n =((n & 0x00ff00ff))+((n>>8) & 0x00ff00ff);
    n =((n & 0x0000ffff))+((n>>16) & 0x0000ffff);
    return n;
}
