#include <stdio.h>

int main(){
	int length;
	scanf("%d", &length);
	int arr[7] = {64,32,16,8,4,2,1};
	int i = 0;
	int cnt = 0;
	while(length != 0){
		if(length >= arr[i]){
			length -= arr[i];
			i = 0;
			cnt++;
		}
		else{
			i++;
		}
	}
	printf("%d", cnt);
}