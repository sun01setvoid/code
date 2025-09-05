#include <climits>
#include <iostream>
//+-*div/
//注意不要溢出
/*+*/
//无进位运算加进位信息
int add(int a,int b){   //b是负数也是对的
    int ans=a;
    while (b!=0){
        ans=a^b;
        b=(a&b)<<1;
        a=ans;
    }
    return ans;
}

/*-*/
int mius(int a,int b){   //a+(-b)
    return add(a,add(~b,1));
}

/*mul*/
int mul(int a,int b){   //b是负数也是对的
    int ans=0;
    while (b!=0){
        if (b&1!=0) ans=add(ans,a);
        a<<=1;
        b>>=1;
    }
}

/*div*/
//整除，整数最小值转换不了非负形式，溢出了

// 必须保证a和b都不是整数最小值，返回a除以b的结果
int divn(int a, int b) {
    int x = a < 0 ? -a : a;
    int y = b < 0 ? -b : b;
    int ans = 0;
    for (int i = 30; i >= 0; i--) { //符号位单独分辨
        if ((x >> i) >= y) {
            ans |= (1 << i);
            x =mius(x, (y << i));
        }
    }
    return (a < 0 ^ b < 0) ? -ans : ans;
}

int divide(int a, int b) {
    if (a == INT_MIN && b == INT_MIN) {
        // a和b都是整数最小
        return 1;
    }
    if (a != INT_MIN && b != INT_MIN) {
        // a和b都不是整数最小，那么正常去除
        return divn(a, b);
    }
    if (b == INT_MIN) {
        // a不是整数最小，b是整数最小
        return 0;
    }
    // a是整数最小，b是-1，返回整数最大，因为题目里明确这么说了
    if (b == -1) {
        return INT_MAX;
    }
    // a是整数最小，b不是整数最小，b也不是-1
    a=add(a,(b > 0 ? b : -b));//加一个
    int ans = divn(a, b);
    int offset = (b > 0) ? -1 : 1;
    return add(ans,offset);
}
