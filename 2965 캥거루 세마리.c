#include <stdio.h>

int main(){
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	int result1 = b - a - 1;
	int result2 = c - b - 1;
	int answer = result1 > result2 ? result1 : result2;
	printf("%d", answer);

	return 0;
}