// 直接使用贪心算法构造哈梅尔线性基，时间复杂度 O(nlogn)，空间复杂度 O(n)
#include <algorithm>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
bool zero;
ull p[64];
void insert(ull x)
{
  for (int i = 60; i >= 0; --i)
  {
    if (!((x >> i) & 1))
      continue;
    if (!p[i])
    {
      p[i] = x;
      break;
    }
    x ^= p[i];
  }
  zero = true;
}
ull ask(ull x)
{
  for (int i = 60; i >= 0; i--)
  {
    if (!((x >> i) & 1))
      x ^= p[i];
  }
  return x;
}