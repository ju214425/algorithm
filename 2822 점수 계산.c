#include <stdio.h>

int main(){
	int arr[8] = {};
	int arrr[8] = {};
	int sum = 0;
	int exception[3];
	for(int i = 0 ; i < 8 ; i++){
		scanf("%d", &arr[i]);
		arrr[i] = arr[i];
	}
	
	for(int j = 0 ; j < 7 ; j++){
		for(int i = 0 ; i < 7 ; i++){
			if(arr[i] > arr[i+1]){
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}

	for(int i = 3 ; i < 8 ; i++){
		sum += arr[i];
	}
	for(int i = 0 ; i < 8 ; i++){
		if(arr[0] == arrr[i]){
			exception[0] = i;
		}
		if(arr[1] == arrr[i]){
			exception[1] = i;
		}
		if(arr[2] == arrr[i]){
			exception[2] = i;
		}
	}
	printf("%d\n", sum);
	for(int i = 0 ; i < 8 ; i++){
		if(i != exception[0] && i != exception[1] && i != exception[2]) printf("%d ", i+1);
	}
}