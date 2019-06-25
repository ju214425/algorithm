#include <stdio.h>
	int chessarr[8][8] = {};
	char arr[8][8] = {};
	int arrr[8][8] = {};
int main(){
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if((i + j) % 2 == 0) chessarr[i][j] = 1; //white
			else{
				chessarr[i][j] = 0; //black
			}
		}
	}
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			scanf(" %c", &arr[i][j]);
			if(arr[i][j] == '.') arrr[i][j] = 0;
			else arrr[i][j] = 1;
		}
	}
	int sum = 0;
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			sum += (arrr[i][j] * chessarr[i][j]);
		}
	}
	printf("%d", sum);
}