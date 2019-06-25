#include <stdio.h>

int main(){
	int numberOfSongs;
	int averageValue;
	scanf("%d %d", &numberOfSongs, &averageValue);
	printf("%d", numberOfSongs * (averageValue - 1) + 1);

	return 0;
}