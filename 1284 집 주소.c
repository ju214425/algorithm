#include <stdio.h>

int main(){
	int number = 1;
	int number2 = 1;
	int i = 1;
	int arr[100000] = {};
	while(number != 0){
		int check;
		int size = 1;
		scanf("%d", &number);
		number2 = number;
		if(number == 0) break;
		while(number2 != 0){
			check = number2 % 10;
			if(check == 0) size += 4;
			else if(check == 1) size += 2;
			else size += 3;
			number2 /= 10;
			size += 1;
		}
		arr[i++] = size;
	}
	int j = 1;
	while(arr[j] != 0){
		printf("%d\n", arr[j]);
		j++;
	}
}