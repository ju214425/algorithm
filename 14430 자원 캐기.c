#include <stdio.h>

int max(int num1, int num2){
	return num1 > num2 ? num1 : num2;
}

int maparr[301][301];
int resultarr[301][301];
int main(){
	int height, width;
	scanf("%d %d", &height, &width);
	for(int i = 1 ; i <= height ; i++){
		for(int j = 1 ; j <= width ; j++){
			scanf("%d", &maparr[i][j]);
		}
	}
	for(int i = 1 ; i <= height ; i++){
		for(int j = 1 ; j <= width ; j++){
			resultarr[i][j] = max(resultarr[i - 1][j],resultarr[i][j - 1]) + maparr[i][j];
		}
	}

	printf("%d", resultarr[height][width]);

	return 0;
}