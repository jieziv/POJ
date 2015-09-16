#include <stdio.h>

char space[10000][10000];
int sort[10000], result[10000];

int main(void)
{
	int n, m;
	int i, j, k, temp;
	char *pch;
	
	scanf("%d%d", &n, &m);
	
	for(i = 0; i < m; i++){
		scanf("%s", space[i]);
		temp = 0;
		for(j = 0; j < n; j++){
			for(k = j + 1; k < n; k++){
				if(space[i][j] > space[i][k])
					temp++;
			}
		}
		sort[i] = temp;
	}
	
	for(j = 0; j < m; j++){
		temp = sort[0];
		k = 0;
		for(i = 0; i < m; i++){
			if(temp > sort[i]){
				temp = sort[i];
				k = i;
			}
		}
		sort[k] = 1<<20;
		result[j] = k;
	}
	for(i = 0; i < m; i++)
		printf("%s\n", space[result[i]]);
	
}

