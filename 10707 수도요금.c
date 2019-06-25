#include <stdio.h>

int min(int number1, int number2){
	return number1 > number2 ? number2 : number1;
}


int main(){
	int A, B, C, D, P;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
	int Xfee, Yfee;
	Xfee = P * A;
	if(P >= C){
		Yfee = B + (P - C) * D;
	}
	else{
		Yfee = B;
	}

	printf("%d", min(Xfee, Yfee));

	return 0;
}