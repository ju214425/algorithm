#include <stdio.h>

int parr[105];
long long arr[105];
int main(){
	int numberOfTest;
	scanf("%d", &numberOfTest);
	for(int i = 1 ; i <= numberOfTest ; i++){
		scanf("%d", &parr[i]);
	}
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for(int i = 6; i < 101 ; i++){
		arr[i] = arr[i-1] + arr[i-5];
	}
	for(int i = 1 ; i <= numberOfTest ; i++){
		printf("%lli\n", arr[parr[i]]);
	}
}