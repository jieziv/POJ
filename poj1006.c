#include <stdio.h>

#define PN 23
#define EN 28
#define IN 33

int main(void)
{
	int p, e, i, d;
	int n, j;
	
	
	j = 1;
	while(scanf("%d%d%d%d", &p, &e, &i, &d) != EOF){
		if(p == -1 && e == -1 && i == -1 && d == -1)
			break;
		n = (5544*p + 14421*e + 1288*i - d)%(23*33*28);
		
		if(n <= 0)
			n = 21252-d;
		printf("Case %d: the next triple peak occurs in %d days.\n", j++, n);
	}
	
	return 0;
}

