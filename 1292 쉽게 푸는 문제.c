#include <stdio.h>

int main(){
	int arr[2500] = {};
	int cnt = 1;
	for(int i = 1 ; i < 50; i++){
		for(int j = 1 ; j <= i ; j++){
			arr[cnt++] = i;
		}
	}
	int start;
	int end;
	scanf("%d %d", &start, &end);
	int sum = 0;
	for(int i = start ; i <= end ; i++){
		sum += arr[i];
	}
	printf("%d", sum);
}