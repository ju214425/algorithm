#include <stdio.h>

int main(){
	int numberOfTest;
	scanf("%d", &numberOfTest);
	int arr[numberOfTest];
	int ansarr[numberOfTest];
	for(int i = 0 ; i < numberOfTest ; i++){
		scnaf("%d", &arr[i]);
	}
	
	for(int i = 0 ; i < numberOfTest ; i++){
		printf("%d\n", ansarr[i]);
	}
}