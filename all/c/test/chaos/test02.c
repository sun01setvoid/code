#include <stdio.h>

 int main(){
	int n;
	double sum=0;
	int i=0;
	int k=1;
	scanf("%d",&n);
	for(i=1;i<=(n-1);i++)
	{
		sum += 1.0/(i * (i+1) * k);
		k = -k;
	}
	printf("%.3lf",sum);
    getchar();
    getchar();
    return 0;
}