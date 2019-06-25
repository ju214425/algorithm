#include <stdio.h>

int check(int number){
	if(number < 100) return 1;
	else{
		if((number/100 + number%10) == 2 * ((number/10)%10)) return 1;
		else return 0;
	}
}

int main(){
	int number;
	scanf("%d", &number);
	int cnt = 0;
	for(int i = 1 ; i <= number ; i++){
		if(check(i) == 1) {
			cnt++;
		}
	}
	printf("%d",cnt);
}