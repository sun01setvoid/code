#include <stdio.h>
#include <math.h>
int main()
{
  double x;
  int n;
  int i = 0;
  int a = 1;
  double sum = 0;
  scanf("%lf%d", &x, &n);
  while (i < n + 1)
  {
    sum += pow(x, i) / a;
    a = (i + 1) * a;
    i++;
  }
  printf("%.4lf", sum);
  return 0;
}