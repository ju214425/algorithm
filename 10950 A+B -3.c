#include <stdio.h>

int num1arr[1000];
int num2arr[1000];

int main(){
	int numberOfTest;
	scanf("%d",&numberOfTest);
	int num1, num2;

	for(int i = 0 ; i < numberOfTest ; i++){
		scanf("%d %d", &num1arr[i] , &num2arr[i]);
	}

	for(int i = 0 ; i < numberOfTest ; i++){
		printf("%d\n", num1arr[i]+num2arr[i]);
	}
	
	return 0;
}