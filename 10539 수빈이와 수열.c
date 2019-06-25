#include <stdio.h>

int main(){
	int lengthOfSequence;
	scanf("%d", &lengthOfSequence);
	int Asequence[lengthOfSequence + 1];
	int Bsequence[lengthOfSequence + 1];
	int sum[lengthOfSequence + 1];
	for(int i = 1 ; i <= lengthOfSequence ; i++){
		scanf("%d", &Asequence[i]);
		sum[i] = Asequence[i] * i;
	}

	Bsequence[1] = Asequence[1];
	for(int i = 2 ; i <= lengthOfSequence ; i++){
		Bsequence[i] = sum[i] - sum[i-1];
	}
	for(int i = 1 ; i <= lengthOfSequence ; i++){
		printf("%d ", Bsequence[i]);
	}

	return 0;
}