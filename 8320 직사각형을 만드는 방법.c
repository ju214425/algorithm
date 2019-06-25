#include <stdio.h>

int main(){
	int numberOfSquare;
	scanf("%d", &numberOfSquare);
	int cnt = 0;
	int i, j;
	for(i = 1 ; i <= numberOfSquare ; i++){
		for(j = i ; j <= numberOfSquare ; j++){
			if((i * j) > numberOfSquare) break;
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}