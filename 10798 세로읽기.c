#include <stdio.h>
#include <string.h>
int main(){
	char text[5][20];
	for(int i = 0 ; i < 5 ; i++){
		scanf("%s", text[i]);
	}
	int i = 0, j = 0;

	while(1){
		if(text[i][j] != '\0') {
			printf("%c", text[i][j]);
			j++;
			if(j == 5){
				i++;
				j = 0;
			}
		}
	}
}