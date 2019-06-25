#include <stdio.h>

int main(){
	int numberOfMultiTap;
	scanf("%d", &numberOfMultiTap);
	int sum = 0;
	int result;
	int temp;
	for(int i = 0 ; i < numberOfMultiTap ; i++){
		scanf("%d", &temp);
		sum += temp;
	}
	result = sum - numberOfMultiTap + 1;
	printf("%d", result);

	return 0;

}