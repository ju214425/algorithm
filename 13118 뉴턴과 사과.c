#include <stdio.h>

int main(){
	int arr[4];
	int xpos;
	int ypos;
	int radius;

	int answer = 0;

	for(int i = 0 ; i < 4 ; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d %d %d", &xpos, &ypos, &radius);

	for(int i = 0 ; i < 4 ; i++){
		if (xpos == arr[i]) answer = i + 1;
	}

	printf("%d", answer);

	return 0;
}