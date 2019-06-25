#include <stdio.h>

int main(){
	int numberOfTest;
	scanf("%d", &numberOfTest);
	int arr[2][numberOfTest];
	int answerArr[numberOfTest];
	for(int i = 0 ; i < numberOfTest ; i++){
		scanf("%d %d", &arr[0][i], &arr[1][i]);
		answerArr[i] = arr[0][i] + arr[1][i];
	}
	for(int i = 0 ; i < numberOfTest ; i++){
		printf("%d\n",answerArr[i]);
	}

	return 0;
}