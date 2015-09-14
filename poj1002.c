#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000

void Deal(char line[], char result[])
{
	int i;
	char *p;
	
	i = 0;
	p = line;
	while(*p != '\0'){
		switch(*p){
			case '0':result[i++] = '0';
					break;
			case '1':result[i++] = '1';
					break;
			case '2':
			case 'A':
			case 'B':
			case 'C':result[i++] = '2';
					break;
			case '3':
			case 'D':
			case 'E':
			case 'F':result[i++] = '3';
					break;
			case '4':
			case 'G':
			case 'H':
			case 'I':result[i++] = '4';
					break;
			case '5':
			case 'J':
			case 'K':
			case 'L':result[i++] = '5';
					break;
			case '6':
			case 'M':
			case 'N':
			case 'O':result[i++] = '6';
					break;
			case '7':
			case 'P':
			case 'R':
			case 'S':result[i++] = '7';
					break;
			case '8':
			case 'T':
			case 'U':
			case 'V':result[i++] = '8';
					break;
			case '9':
			case 'W':
			case 'X':
			case 'Y':result[i++] = '9';
					break;
			default:	;
		}
		p++;
		if(i > 6)
			break;
	}
	result[8] = '\0';
}

int main(void)
{
	int n, i, j, k, temp, temp1;
	int m[M], l[M], num[M];
	char p[1000][90], q[1000][90];
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%s", p[i]);
		Deal(p[i], q[i]);
	}
	
	
	for(i = 0; i < M; i++){
		m[i] = 1;
	}
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(strcmp(q[i], q[j]) == 0){
				q[j][0] = '\0';
				m[i]++;
				m[j]--;
			}
		}
	}
	
	k = 0;
	for(i = 0; i < n; i++){
		if(q[i][0] != '\0' && m[i] > 1){
			for(j = 0; j < 7; j++){
				num[k] *= 10;
				temp = q[i][j] - '0';
				num[k] += temp;
			}
			l[k] = m[i];
			k++;
		}
	}
	
	for(i = 0; i < k; i++){
		for(j = i+1; j < k; j++){
			if(num[i] > num[j]){
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
				temp1 = l[i];
				l[i] = l[j];
				l[j] = temp1;
			}
		}
	}
	
	for(i = 0; i < k; i++){
		temp = num[i];
		for(j = 7; j >= 0; j--){
			if(j == 3){
				q[i][j] = '-';
			}
			else{
				q[i][j] = '0' + temp%10;
				temp /= 10;
			}
		}
		q[i][8] = '\0';
	}
	
	if(k == 0){
		printf("No duplicates.\n");
	}
	for(i = 0; i < k; i++){
		printf("%s %d\n", q[i], l[i]);
	}
}


