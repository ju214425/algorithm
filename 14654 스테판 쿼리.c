#include <stdio.h>

int check[2][305];

int main(){
	int numberOfRound;
	scanf("%d", &numberOfRound);
	int AceArr[numberOfRound];
	int NewYorkArr[numberOfRound];
	int succesive = 0;
	for(int i = 1 ; i <= numberOfRound ; i++){
		scanf("%d", &AceArr[i]);
	}
	for(int i = 1 ; i <= numberOfRound ; i++){
		scanf("%d", &NewYorkArr[i]);
	}
	for(int i = 1 ; i <= numberOfRound ; i++){
		if(AceArr[i] == NewYorkArr[i]){
			if(check[0][i-1] == 0){
				check[0][i] = 1;
				check[1][i] = 0;
			}
			else{
				check[0][i] = 0;
				check[1][i] = 1;
			}
		} //무승부 -> 늦게 온 사람 승리
		if((AceArr[i] == 1 && NewYorkArr[i] == 3) || (AceArr[i] == 2 && NewYorkArr[i] == 1) 
			|| (AceArr[i] == 3 && NewYorkArr[i] == 2)){
			check[0][i] = check[0][i-1] + 1;
			check[1][i] = 0;
		} //에이스 승리
		if((AceArr[i] == 1 && NewYorkArr[i] == 2) || (AceArr[i] == 2 && NewYorkArr[i] == 3) 
			|| (AceArr[i] == 3 && NewYorkArr[i] == 1)){
			check[1][i] = check[1][i-1] + 1;
			check[0][i] = 0;
		} //뉴욕 승리
	}
	for(int i = 0 ; i <= numberOfRound ; i++){
		if(succesive < check[0][i]) succesive = check[0][i];
	}
	for(int i = 0 ; i <= numberOfRound ; i++){
		if(succesive < check[1][i]) succesive = check[1][i];
	}
	printf("%d", succesive);
}