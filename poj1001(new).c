#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 1000
#define S 10000

int D2I(char R[], int *blen)
{
	int i, result;
	char *p;
	char pre[M], back[M];
	
	p = R;		
	while(*p == '0')
		p++;
	
	i = 0;
	while(*p != '\0'){
		if(*p != '.')
			pre[i++] = *p++;
		else{
			p++;
			break;
		}		
	}
	pre[i] = '\0';
		
	i = 0;
	while(*p != '\0'){
		back[i++] = *p;
		p++;
	}
	back[i] = '\0';	
	*blen = strlen(back);
	
	while(back[--(*blen)] == '0'){
		back[*blen] = '\0';
	}
	
	*blen = strlen(back);
		
	result = atoi(back) + atoi(pre)*pow(10,*blen);	
	
	return result;
}

void Dul(int result, char E[M], int n, int blen)
{
	int A[M], B[M], C[M];
	int m, i, j, k, temp, dot, bit, one;
	char D[M], ch, *p, *q;
	
	if(n == 0){
		printf("1\n");
		return;
	}
	if(result == 0){
		printf("0\n");
		return;
	}
	
	i = 1;
	A[0] = 0;
	B[0] = 0;
	temp = result;
	while(temp){
		A[0]++;
		B[0]++;
		A[i] = temp % S;
		B[i] = A[i];
		
		temp /= S;
		i++;
	}
	
	m = 1;	
	while(m < n){
		for(i = 1; i <= A[0]; i++){
			k = i;
			for(j = 1; j <= B[0]; j++){
				C[k] += A[i] * B[j];
				C[0] = k;
				if(C[k] / S){
					C[k+1] += C[k] / S;
					C[k] = C[k] % S;
					C[0] = k+1;
				}
				k++;
			}
		}
		
		m++ ;
		for(i = 0; i <= C[0]; i++){
			A[i] = C[i];
			
			if(i != 0)
				C[i] = 0;
		}
		A[0] = C[0];
		C[0] = 0;
	}
	
	temp = S/10;
	bit = 0;
	while(temp){
		temp /= 10;
		bit++;
	}
	
	j = 0;
	for(i = 1; i <= A[0]; i++){
		temp = A[i];
		k = bit;
		while(k--){
			D[j++] = '0' + temp % 10;
			temp /= 10;
		}	
	}
	D[j] = '\0';
	
	
	p = &D[j-1];
	while(*p == '0'){
		*p = '\0';
		p--;
	}
	
	p = D;
	if(blen != 0){
		while(*p == '0'){
			*p = '\0';
			p++;
		}
	}
	
	q = p;
	for(i = 0; i < n*blen; i++){
		if(*q == '\0'){
			*q = '0';
			*(q+1) = '\0';
		}
		q++;
	}
	
	q = p; 
	while(*q != '\0')
		q++;
	q--;
	
	j = strlen(p);
	i = 0;
	while(*q != '\0'){
		if(i == j-n*blen){
			E[i++] = '.';
		}
		E[i++] = *q--;
	}
	E[i] = '\0';
}

int main(void)
{
	char R[M], E[M];
	int n, blen, i;
	int result;

	while(scanf("%s%d", R, &n) == 2){
		result = D2I(R, &blen);
		Dul(result, E, n, blen);
		puts(E);
	}
}
