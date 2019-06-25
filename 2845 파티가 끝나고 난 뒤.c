#include <stdio.h>

int arr[5];

int main(){
	int peopleperArea;
	int Area;
	int numberOfPeople;
	scanf("%d %d", &peopleperArea, &Area);
	numberOfPeople = peopleperArea * Area;
	for(int i = 0 ; i < 5 ; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 0 ; i < 5 ; i++){
		printf("%d ", arr[i] - numberOfPeople);
	}
}