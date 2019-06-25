#include <stdio.h>

int main(){
	int numberOfPlay;
	scanf("%d", &numberOfPlay);
	int numberarr[numberOfPlay + 1], maximumIntegerarr[numberOfPlay + 1];
	int result[numberOfPlay + 1];
	int minimum;
	int answer;
	for(int i = 1 ; i <= numberOfPlay ; i++){
		scanf("%d %d", &numberarr[i], &maximumIntegerarr[i]);
	}
	for(int i = 1 ; i <= numberOfPlay ; i++){
		result[i] = (((numberarr[i] - 1) / (maximumIntegerarr[i] + 1)) + 1) * 2;
	}
	minimum = result[1];
	answer = 1;
	for(int i = 2 ; i <= numberOfPlay ; i++){
		if(minimum > result[i]){
			minimum = result[i];
			answer = i;
		}
	}
	printf("%d %d", answer, minimum);

	return 0;
}