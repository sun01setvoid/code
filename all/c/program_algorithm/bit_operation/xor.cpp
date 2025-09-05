// 可以看作无进位相加!!!!!!
// 满足结合率和交换律
// 0^n=0,n^n=0
// a^b=c,c^b=a,c^a=b;
//&上所有各不相同，等于&所有的异或不等于0

/*异或运算交换数字*/
void swapxor(int &a, int &b)
{
    a = a ^ b, b = a ^ b, a = a ^ b;
}

/*不用比较操作返回最大值*/
int flip(int x)
{
    return x ^ 1;
}

int sign(int x)
{
    return flip(x >> 31 & 1);
}

int getMax(int a, int b)
{
    int c = a - b;
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    int diffAB = sa ^ sb;
    int sameAB = flip(diffAB);               // 互斥
    int returnA = diffAB * sa + sameAB * sc; // returnA为1的条件
    int returnB = flip(returnA);             // 互斥
    return a * returnA + b * returnB;
}

/*找所有数中缺失的一个数*/
// 全体异或和^缺一异或和

/*找唯一出现奇数次的数*/
// 全部异或

/*找唯二出现过奇数次的数*/
// xor（整体异或的）后一定有一个位是1，是1，则这两个数在这个位置上不同，一个是0，一个是1
// int rightone=xor&(-xor)//获得一个1
// 将原来的分类（&rightone是1还是0），异或其中一类（xor)，得到其中一个答案xor1，
//xor^xor1就是另一个xor2
// 分别异或也可以得到答案了，就是分成两类了，把两个出现奇数次的数分开了

/*一种数不够m次，其他数都m次*/
// 记录cnts[i]每个位置上的i的数
// 求ans,如果cnt[i]%m!=0,ans|=1<<i;