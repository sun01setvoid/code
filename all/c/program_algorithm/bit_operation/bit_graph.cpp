//hash查找，f（X->int）,每个int存储是否存在

//必须为连续且不能过大,一个数只占用一个bit的空间

//x/32看第几个整数，x%32看是否出现，用bit是否出现,int arr[]
//要求一开始就给连续区间，不要太大,准备(n+31)/32个区间
//  a/b向上取整==(a+b-1)/b  ！！！

#include <iostream>
#include <bitset>
#include <cassert>

using namespace std;
const int N=50;

//手写 大小为[(N>>5)+1]看位数
//add :set[num/32]|=1<<(num%32)
//remove  :set[num/32]&=~(1<<(num%32))
//reverse  :set[num/32]^=1<<(num%32)
//boolean : return (set[num/32]>>(num%32))&1
int main(){
    std::bitset<N> bitset1; // 创建一个长度为 N 的 bitset，所有位都被初始化为 0
    int value=100;

    std::bitset<N> bitset2(value); // 使用二进制整数 value 初始化一个长度为 N 的 bitset
    std::bitset<32> bitset21(0xffff);          // bits 0 ... 15 are set to 1; 16 ... 31 are 0
    std::bitset<128> bitset22(0xffff);         // bits 32 through 127 initialized to zero
    
    std::bitset<N> bitset3(string); // 使用二进制字符串 string 初始化一个长度为 N 的 bitset
    string str("1111111000000011001101");
    std::bitset<N> bitset31(str);    //用整个字符串来初始化bitset
    std::bitset<32> bitset32(str, 5, 4); // 4 bits starting at str[5], 1100
    std::bitset<32> bitset33(str, str.size() - 4);     // use last 4 characters
    
    std::bitset<N> bitset4(bitset1); // 使用另一个 bitset 初始化一个长度为 N 的 bitset
    const int pos=30,n=30;
    //不能pos,n
    std::bitset<N> bitset5(bitset4);	  //bitset5是bitset4中从位置pos开始的n个位的副本
    ///容量必须使用一个常量,n与N相等就行


    typedef std::size_t length_t, position_t; // 提示
 
    // 构造函数：
    constexpr std::bitset<4> b1;
    constexpr std::bitset<4> b2{0xA}; // == 0B1010
    std::bitset<4> b3{"0011"}; // C++23 起也可以为 constexpr
    std::bitset<8> b4{"ABBA", length_t(4), /*0:*/'A', /*1:*/'B'}; // == 0B0000'0110
 
    // 能打印出 bitset 到流：
    std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << "; b4:" << b4 << '\n';
 
    // bitset 支持逐位运算：
    //<< 和 >> 也行
    b3 |= 0b0100; assert(b3 == 0b0111);
    b3 &= 0b0011; assert(b3 == 0b0011);
    b3 ^= std::bitset<4>{0b1100}; assert(b3 == 0b1111);
 
    // 整个集合上的操作：
    b3.reset(); assert(b3 == 0);
    b3.set(); assert(b3 == 0b1111);
    assert(b3.all() && b3.any() && !b3.none());
    b3.flip(); assert(b3 == 0);
 
    // 单独位上的操作:
    b3.set(position_t(1), true); assert(b3 == 0b0010);
    b3.set(position_t(1), false); assert(b3 == 0);
    b3.flip(position_t(2)); assert(b3 == 0b0100);
    b3.reset(position_t(2)); assert(b3 == 0);
 
    // 支持下标 operator[]：
    b3[2] = true; assert(true == b3[2]);
 
    // 其他操作：
    assert(b3.count() == 1);
    assert(b3.size() == 4);
    assert(b3.to_ullong() == 0b0100ULL);
    assert(b3.to_string() == "0100");
    b3.any();
    b3.all();
    b3.none();
}