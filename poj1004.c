#include <stdio.h>

int main(void)
{
	double input, sum;
	int i;
	
	sum = 0.0;
	for(i = 0; i < 12; i++){
		scanf("%lf", &input);
		sum += input;
	}
	printf("$%.2f\n", sum/12.0*1000)+5)/1000.0);//四舍五入
}
