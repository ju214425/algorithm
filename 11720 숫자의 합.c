#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int number;
	scanf("%d", &number);
	char a;
	int retNumber = 0;
	a = getchar();

	for(int i = 0 ; i < number ; i++){
		retNumber += (a - '0');
		a = getchar();
	}

	printf("%d", retNumber);

	return 0;
}