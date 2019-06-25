#include <stdio.h>

int main(){
	int e, f, bottleNeeded;
	int emptyBottles = 0;
	int newBottles = 0;
	int result = 0;
	scanf("%d %d %d", &e, &f, &bottleNeeded);
	emptyBottles = e + f;
	while(emptyBottles >= bottleNeeded){
		result += (emptyBottles / bottleNeeded);
		newBottles = (emptyBottles / bottleNeeded);
		emptyBottles = (emptyBottles % bottleNeeded) + newBottles;
	}
	printf("%d\n", result);

	return 0;
}