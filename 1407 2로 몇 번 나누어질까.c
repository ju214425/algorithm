#include <stdio.h>

int function(int number){
	int cnt = 0;
	while(number % 2 == 0){
		number /= 2;
		cnt++;
	}
	int result = 1;
	for(int i = 0 ; i < cnt ; i++){
		result *= 2;
	}
	return result;
}

int main(){
	long long int arr[1000000] = {};
	int num1, num2;
	int sum = 0;
	for(int i = num1 ; i <= num2 ; i++){
		arr[i] = function(i);
		sum += arr[i];
	}
	printf("%d", sum);
}