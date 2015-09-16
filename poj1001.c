#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 1000

int D2I(char R[], int *blen, int *plen)
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
	*plen = strlen(pre);
		
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

void Dul(int result, int n, int blen, int plen)
{
	int i, j, k, m, len;
	int A[M], B[M], C[M];
	char D[M], *p;
	int temp;
	
	if(result == 0){
		printf("0\n");
		return;
	}
	for(i = 0; i < M; i++){
		A[i] = -1;
		B[i] = -1;
		C[i] = 0;
	}
	
	i = 0;
	temp = result;
	while(temp != 0){
		A[i] = temp % 10;
		B[i] = temp % 10;
		if(n == 1)
			C[i] = temp % 10;
		temp /= 10;
		i++;
	}
	
	m = n;
	while(--m){
		i = 0;
		while(A[i] != -1){
			j = 0;
			k = i;
			while(B[j] != -1){
				C[k] += A[i] * B[j];
				C[k+1] += C[k]/10;
				C[k] = C[k]%10;
				k++;
				j++;
			}
			i++;
		}
		
		for(i = 0; i <= k; i++)
		{
			B[i] = C[i];
			C[i] = 0;
		}
	}
	
	if(plen != 0){
		i = (blen+plen)*n;
		while(B[i] == -1)
			i--;
	
		j = 0;
		while(i >= 0){
			if(i == blen * n-1){
				D[j] = '.';
				j++;
			}	
			D[j] ='0' + B[i--];
			j++;
		}
		D[j] = '\0';
	}
	else{
		j = 0;
		i = blen*n-1;
		D[j++] = '.';
		while(i >= 0){
			if(B[i] == -1)
				B[i] = 0;
			D[j] ='0' + B[i--];
			j++;
		}
		D[j] = '\0';
	}
	
	len = strlen(D);
	while(D[--len] == '0' && blen != 0){
		D[len] = '\0';
	}
	
	p = D;
	while(*p == '0'){
		p++;
	}
	printf("%s", p);
	printf("\n");
}

int main(void)
{
	char R[M];
	int n, plen, blen, i;
	int result;

	while(scanf("%s%d", R, &n) == 2){
		result = D2I(R, &blen, &plen);
		Dul(result, n, blen, plen);
	}
}
