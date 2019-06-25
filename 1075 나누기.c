#include <stdio.h>

int main(){
	int N, F;
	scanf("%d %d", &N, &F);
	N = (N/100) * 100;
	int result;
	if(N % F == 0) result = 0;
	else {
		result = F - (N % F);
	}
	if(result < 10) printf("0%d", result);
	else{
		printf("%d",result);
	}
}