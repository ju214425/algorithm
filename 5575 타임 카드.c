#include <stdio.h>

int main(){
	int arr[3][6];
	int time[3][3];
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 6 ; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			time[i][j] = arr[i][j + 3] - arr[i][j];
		}
	}
	
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			if(time[i][j] < 0){
				time[i][j] += 60;
				time[i][j-1] -= 1;
			}
		}
	}

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			if(time[i][j] < 0){
				time[i][j] += 60;
				time[i][j-1] -= 1;
			}
		}
	}
	
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			printf("%d ", time[i][j]);
		}
		printf("\n");
	}

	return 0;
}