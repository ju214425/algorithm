#include <stdio.h>

int main(){
	int arr[9] = {};
	int max = 0;
	int order;
	for(int i = 0 ; i < 9 ; i++){
		scanf("%d", &arr[i]);
		if(max < arr[i]) {
			max = arr[i];
			order = i;
		}
	}
	printf("%d\n%d", max, order + 1);

	return 0;
}