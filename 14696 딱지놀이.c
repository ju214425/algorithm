#include <stdio.h>

int main(){
	int numberOfLine;
	int Aarr[5] = {};
	int Barr[5] = {};
	char answerArr[102];
	int Atimes, Btimes, input;
	scanf("%d", &numberOfLine);
	for(int i = 1 ; i <= numberOfLine ; i++){
		scanf("%d", &Atimes);
		for(int j = 1 ; j <= Atimes ; j++){
			scanf("%d", &input);
			Aarr[input]++; 
		}
		scanf("%d", &Btimes);
		for(int j = 1 ; j <= Btimes ; j++){
			scanf("%d", &input);
			Barr[input]++;
		}

		for(int j = 4 ; j > 0 ; j--){
			if(Aarr[j] > Barr[j]){
				answerArr[i] = 'A';
				break;
			}
			else if(Aarr[j] < Barr[j]){
				answerArr[i] = 'B';
				break;
			}
			if(Aarr[1] == Barr[1]){
				answerArr[i] = 'D';
			}
		}

		for(int i = 1 ; i < 5 ; i++){
			Aarr[i] = Barr[i] = 0;
		}
	}

	for(int i = 1 ; i <= numberOfLine ; i++){
		printf("%c\n", answerArr[i]);
	}

	return 0;
}

