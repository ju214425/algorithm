#include <stdio.h>

int main(){
	int number1;
	int number2;
	int average;
	scanf("%d %d", &number1, &average);
	number2 = average * 2 - number1;
	printf("%d", number2);

	return 0;
}