#include <stdio.h>

int main(){
	int number;
	scanf("%d", &number);
	int arr[5];
	int cnt = 0;
	for(int i = 0 ; i < 5 ; i++){
		scanf("%d", &arr[i]);
		if(arr[i] == number) cnt++;
	}
	printf("%d", cnt);
}