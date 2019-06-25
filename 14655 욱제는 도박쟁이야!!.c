#include <stdio.h>

int absoluteValue(int number){
	return number > 0 ? number : -number;
}

int main(){
	int numberOfCoin;
	scanf("%d", &numberOfCoin);
	int coinArr1[numberOfCoin + 4];
	int coinArr2[numberOfCoin + 4];
	for(int i = 2 ; i < numberOfCoin + 2 ; i++){
		scanf("%d", &coinArr1[i]);
	}
	for(int i = 2 ; i < numberOfCoin + 2 ; i++){
		scanf("%d", &coinArr2[i]);
	}

}