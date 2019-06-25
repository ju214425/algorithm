#include <stdio.h>

int main(){
	int numberOfPeople;
	scanf("%d", &numberOfPeople);
	int arr[numberOfPeople];
	int sum = 0;
	for(int i = 0 ; i < numberOfPeople ; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if(numberOfPeople > sum * 2) printf("Junhee is not cute!");
	else printf("Junhee is cute!");

	return 0;
}