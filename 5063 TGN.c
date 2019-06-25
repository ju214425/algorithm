#include <stdio.h>

int main(){
	int numberOfTest;
	scanf("%d", &numberOfTest);
	int r[numberOfTest];
	int e[numberOfTest];
	int c[numberOfTest];
	int resultarr[numberOfTest];
	for(int i = 0 ; i < numberOfTest ; i++){
		scanf("%d %d %d", &r[i], &e[i], &c[i]);
		if(e[i] - c[i] > r[i]) resultarr[i] = 1; //advertise
		else if(e[i] - c[i] == r[i]) resultarr[i] = 0; //does not matter
		else resultarr[i] = -1; // do not advertise;
	}
	for(int i = 0 ; i < numberOfTest ; i++){
		if(resultarr[i] == 1) printf("advertise\n");
		else if(resultarr[i] == 0) printf("does not matter\n");
		else printf("do not advertise\n");
	}

	return 0;
}