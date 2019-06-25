#include <stdio.h>

int main(){
	int numberOfPlayer;
	scanf("%d", &numberOfPlayer);
	int arr[numberOfPlayer][3];
	int point[numberOfPlayer];
	for(int i = 0 ; i < numberOfPlayer ; i++){
		for(int j = 0 ; j < 3 ; j++){
			scanf("%d", &arr[i][j]);
		}		
	}
}