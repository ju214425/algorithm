#include <stdio.h>

int main(){
	int mingukArr[4], manseArr[4], mingukSum = 0, manseSum = 0;
	scanf("%d %d %d %d", &mingukArr[0], &mingukArr[1], &mingukArr[2], &mingukArr[3]);
	scanf("%d %d %d %d", &manseArr[0], &manseArr[1], &manseArr[2], &manseArr[3]);
	for(int i = 0 ; i < 4 ; i++){
		mingukSum += mingukArr[i];
		manseSum += manseArr[i];
	}
	printf("%d", mingukSum > manseSum ? mingukSum : manseSum);
}