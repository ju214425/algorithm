#include <stdio.h>

int main(){
	int numberOfMatches, Width, Height;
	scanf("%d %d %d", &numberOfMatches, &Width, &Height);
	int matcharr[numberOfMatches];
	for(int i = 0 ; i < numberOfMatches ; i++){
		scanf("%d", &matcharr[i]);
	}
	for(int i = 0 ; i < numberOfMatches ; i++){
		if( (Width * Width + Height * Height) >= (matcharr[i] * matcharr[i]) ){
			printf("DA\n");
		}
		else{
			printf("NE\n");
		}
	}
}