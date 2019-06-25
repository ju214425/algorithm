#include <stdio.h>
#include <math.h>

long int check(long int number1, long int snumber){
	if( (number1)*(number1 + 1) <= 2 * snumber && 2 * snumber < ((number1 + 1)*(number1 + 2)) ){
		return number1;
	}
	else return number1 - 1;
}

int main(){
	long int S;
	scanf("%ld", &S);
	printf("%ld\n", check(sqrt(2 * S), S));
	
	return 0;
}