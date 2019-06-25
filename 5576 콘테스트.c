#include <stdio.h>

void swap(int *number1, int *number2){
	int temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}

int main(){
	int Warr[10];
	int Karr[10];
	int Wsum = 0;
	int Ksum = 0;
	for(int i = 0 ; i < 10 ; i++){
		scanf("%d", &Warr[i]);
	}
	for(int i = 0 ; i < 10 ; i++){
		scanf("%d", &Karr[i]);
	}
	for(int j = 0 ; j < 9 ; j++){
		for(int i = 0 ; i < 9 ; i++){
			if(Warr[i] > Warr[i+1]) swap(&Warr[i], &Warr[i+1]);
		}
	}
	for(int j = 0 ; j < 9 ; j++){
		for(int i = 0 ; i < 9 ; i++){
			if(Karr[i] > Karr[i+1]) swap(&Karr[i], &Karr[i+1]);
		}
	}

	for(int i = 7 ; i < 10 ; i++){
		Wsum += Warr[i];
		Ksum += Karr[i];
	}
	printf("%d %d", Wsum, Ksum);

	return 0;
}