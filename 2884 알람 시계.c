#include <stdio.h>

int main(){
	int prehour;
	int preminute;
	int hour;
	int minute;
	scanf("%d %d", &prehour, &preminute);
	 
	if(prehour == 0){
		if(preminute >= 45){
			hour = prehour;
			minute = preminute - 45;
		}
		else{
			hour = 23;
			minute = preminute + 15;
		}
	}
	else{
		if(preminute >= 45){
			hour = prehour;
			minute = preminute - 45;
		}
		else{
			hour = prehour - 1;
			minute = preminute + 15;
		}
	}
	printf("%d %d", hour, minute);

	return 0;
}