#include <stdio.h>

int main(){
	int arr[29];
	int temp[31] = {};
	for(int i = 1 ; i <= 28 ; i++){
		scanf("%d", &arr[i]);
		for(int j = 1 ; j <= 30 ; j++){
			if(arr[i] == j) {
				temp[j] = j;
				break;
			}
		}
	}
	for(int i = 1 ; i <= 30 ; i++){
		if(temp[i] == 0){
			printf("%d\n", i);
		}
	}

	return 0;
}