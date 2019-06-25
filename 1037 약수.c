#include <stdio.h>

int main(){
	int numberOfPrime;
	scanf("%d",&numberOfPrime);
	int arr[numberOfPrime];
	for(int i = 0 ; i < numberOfPrime ; i++){
		scanf("%d", &arr[i]);
	}
	for(int j = 0 ; j < numberOfPrime - 1 ; j++){
		for(int i = 0 ; i < numberOfPrime - 1 ; i++){
			if(arr[i] > arr[i+1]){
				int temp;
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	printf("%d",arr[0] * arr[numberOfPrime-1]);
	
}