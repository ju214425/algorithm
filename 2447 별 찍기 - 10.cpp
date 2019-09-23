#include <cstdio>

void star(int n){
	if(n == 0) return;
	printf("***\n* *\n***");
	star(n-1);
}

int main(){
	int n;
	scanf("%d", &n);
	int val = 1;
	int check = 0;
	for(int i = 1 ; i < 8 ; i++){
		val *= 3;
		if(val == n){
			check = i;
			break;
		}
	}

	star(check);
}