#include <stdio.h>

int main(){
	int sec[4];
	int sum = 0;
	int minute;
	int second;
	for(int i = 0 ; i < 4 ; i++){
		scanf("%d", &sec[i]);
		sum += sec[i];
	}
	minute = sum / 60;
	second = sum % 60;

	printf("%d\n%d", minute, second);

	return 0;
}