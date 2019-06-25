#include <stdio.h>

int main(){
	int numberOfTest;
	scanf("%d", &numberOfTest);
	int arr[numberOfTest][7];
	int sum[numberOfTest];
	int minimum[numberOfTest];
	for(int i = 0 ; i < numberOfTest ; i++){
		sum[i] = 0;
		minimum[i] = 100;
	}
	for(int i = 0 ; i < numberOfTest ; i++){
		for(int j = 0 ; j < 7 ; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	for(int i = 0 ; i < numberOfTest ; i++){
		for(int j = 0 ; j < 7 ; j++){
			if(arr[i][j] % 2 == 0) {
				sum[i] += arr[i][j];
				if(minimum[i] > arr[i][j]) minimum[i] = arr[i][j];
			}
		}
	}

	for(int i = 0 ; i < numberOfTest ; i++){
		printf("%d %d\n", sum[i], minimum[i]);
	}

	return 0;
}