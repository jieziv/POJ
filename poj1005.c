#include <stdio.h>

#define PI 3.1415926

int main(void)
{
	int n, i, year[100];
	double x, y;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%lf%lf", &x, &y);
		year[i] = (int)(PI/2*(x*x+y*y))/50+1;
	}
	for(i = 0; i < n; i++){
		printf("Property %d: This property will begin eroding in year %d.\n", i+1, year[i]);
	}
	printf("END OF OUTPUT.");
}


