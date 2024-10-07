#include <stdio.h>
#define inf 1000000

int main(){
	int numberOfUser;
	int numberOfRelation;
	scanf("%d %d", &numberOfUser, &numberOfRelation);
	int friendarr[numberOfUser+1][numberOfUser+1];
	int answer[numberOfUser+1];

	for(int i = i ; i <= numberOfUser ; i++){
		for(int j = 1 ; j <= numberOfUser ; j++){
			 friendarr[i][j] = inf;
		}
	}

	for(int i = 1 ; i <= numberOfRelation ; i++){
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		friendarr[num1][num2] = friendarr[num2][num1] = 1;
	}

	for(int k = 1 ; k <= numberOfUser ; k++){
		for(int i = 1 ; i <= numberOfUser ; i++){
			for(int j = 1 ; j <= numberOfUser ; j++){
				if(friendarr[i][j] >= friendarr[i][k] + friendarr[k][j]) 
					friendarr[i][j] = friendarr[i][k] + friendarr[k][j];
			}
		}
	}
	for(int i = 1 ; i <= numberOfUser ; i++){
		friendarr[i][i] = 0;
	}

	int bacon[numberOfUser + 1];
	for(int i = 1 ; i <= numberOfUser ; i++){
		bacon[i] = 0;
	}

	for(int i = 1 ; i <= numberOfUser ; i++){
		for(int j = 1 ; j <= numberOfUser ; j++){
			bacon[i] += friendarr[i][j] ;
		}
	}
	
	 int min = bacon[1];
	 int number = 1;
	 for(int i = 2 ; i <= numberOfUser ; i++){
	 	if(bacon[i] < min){
	 		min = bacon[i];
	 		number = i;
	 	}
	 }
	  printf("%d", number);

	  return 0;
}