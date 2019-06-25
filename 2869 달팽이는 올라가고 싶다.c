#include <stdio.h>

int main(){
	int climbUp, climbDown, height;
	int answer;
	scanf("%d %d %d", &climbUp, &climbDown, &height);
	int cnt = 0;
	int test = height - climbUp;
	while(test > 0){
		test -= (climbUp - climbDown);
		cnt++; 
	}
	answer = cnt + 1;
	printf("%d" , answer);

	return 0;
}