#include <stdio.h>

int min(int num1, int num2){
	return num1 > num2 ? num2 : num1;
}

int main(){
	int sang;
	int jung;
	int ha;
	int coke;
	int sprite;
	scanf("%d %d %d %d %d", &sang, &jung, &ha, &coke, &sprite);
	int result;
	result = min(sang, min(jung, ha)) + min(coke, sprite) - 50;
	printf("%d", result);

	return 0;
}