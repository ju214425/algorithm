#include <stdio.h>

int main(){
	int numberOfPeople;
	scanf("%d", &numberOfPeople);
	int arr[numberOfPeople + 1];
	int cnt = 0;
	for(int i = 1 ; i <= numberOfPeople ; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 1 ; i <= numberOfPeople ; i++){
		if(arr[i] != i) cnt++;
	}
	printf("%d", cnt);
}