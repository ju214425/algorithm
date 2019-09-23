#include <cstdio>
#include <vector>
#include <algorithm>

int clocknum(int num){
	int temp = num;
	for(int i = 0 ; i < 3 ; i++){
		num = num % 1000 * 10 + num / 1000;
		if(temp > num) temp = num;
	}
	return temp;
}

int main(){
	int a, b, c, d;
	int cnt = 0;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int number = 1000 * a + 100 * b + 10 * c + d;
	int clock = clocknum(number);
	
	for(int i = 1111 ; i <= clock ; i++){
		if(clocknum(i) == i) cnt++;
	}

	printf("%d", cnt);
}