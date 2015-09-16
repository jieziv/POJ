#include <stdio.h>

int main(void)
{
	int num[10000];
	int i = 0, j;
	float input, sum;
	
	scanf("%f", &input);
	while(input > 0.0){
		sum= 0.0;
		for(j = 2; input-sum > 1.0/j; j++){
			sum  += 1.0/j;
		}
		num[i++] = j-1;
		scanf("%f", &input);
	}
	
	for(j = 0; j < i; j++){
		printf("%d card(s)\n", num[j]);
	}	
}


