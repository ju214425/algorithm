#include <stdio.h>

int main(){
	int priceOfTotal;
	int bookarr[9];
	int sum = 0;
	scanf("%d", &priceOfTotal);
	for(int i = 0 ; i < 9 ; i++){
		scanf("%d", &bookarr[i]);
		sum += bookarr[i];
	}
	printf("%d", priceOfTotal - sum);

	return 0;
}