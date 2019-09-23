#include <cstdio>

#define MAX 10000

int arr[MAX+1];

int constructor(int number){
	int sum = 0;
	int tmp = number;
	while(tmp != 0){
		sum += (tmp % 10);
		tmp /= 10;
	}
	sum += number;
	return sum;
}

int main(){
	int cnt = 1;
	for(int i = 1 ; i <= MAX ; i++){
		arr[i] = i;
	}

	while(cnt <= MAX){
		int temp = cnt;
		while(temp <= MAX){
			int val = constructor(temp);
			arr[val] = 0;
			temp = val;
		}
		cnt++;
	}

	for(int i = 1 ; i <= MAX ; i++){
		if(arr[i] != 0) printf("%d\n", i);
	}

	return 0;
}