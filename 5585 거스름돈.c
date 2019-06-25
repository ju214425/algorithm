#include <stdio.h>

int main(){
	int change;
	int price;
	int sum = 0;
	scanf("%d", &price);
	change = 1000 - price;
	while(change >= 500){
		change -= 500;
		sum++;
	}
	while(change >= 100){
		change -= 100;
		sum++;
	}
	while(change >= 50){
		change -= 50;
		sum++;
	}
	while(change >= 10){
		change -= 10;
		sum++;
	}
	while(change >= 5){
		change -= 5;
		sum++;
	}
	while(change >= 1){
		change -= 1;
		sum++;
	}
	printf("%d", sum);

	return 0;
}