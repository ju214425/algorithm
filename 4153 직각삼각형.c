#include <stdio.h>

int max(int num1, int num2, int num3){
	if(num1 >= num2){
		if(num2 >= num3) return num1;
		else if(num1 >= num3) return  num1;
		else return num3;
	}
	else{
		if(num1 >= num3) return num2;
		else if(num2 >= num3) return num2;
		else return num3;
	}
}

int main(){
	int a, b, c;
	int w,h;
	int arr[200000] = {};
	int i = 0;
	int j = 0;
	do{
		scanf("%d %d %d", &a, &b, &c);
		if(max(a,b,c) == a){
			w = b;
			h = c;
		}
		else if(max(a,b,c) == b){
			w = a;
			h = c;
		}
		else{
			w = a;
			h = b;
		}
		if(max(a,b,c) * max(a,b,c) == (w * w) + (h * h)) arr[i] = 1;
		else arr[i] = 2;
		i++;
	}
	while(a + b + c != 0);
	i--;
	for(int j = 0 ; j < i ; j++){
		if(arr[j] == 1) printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}