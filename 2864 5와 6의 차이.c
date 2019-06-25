#include <stdio.h>

int multiplier(int number, cmp){
	for(int i = 0 ; i < cmp ; i++){
		number *= 10;
	}
}
int main(){
	int a, b, a_temp, b_temp, max, min, a_cnt = 0, b_cnt = 0;
	scanf("%d %d", &a, &b);
	a_temp = a;
	b_temp = b;
	while(a_temp != 0){
		a_cnt++;
		a_temp /= 10;
	}
	while(b_temp != 0){
		b_cnt++;
		b_temp /= 10;
	}
	int Aarr[a_cnt];
	int Barr[b_cnt];
	for(int i = a_cnt - 1 ; i >= 0 ; i--){
		Aarr[i] = (a/10);
		a /= 10;
	}
	for(int i = b_cnt - 1 ; i >= 0 ; i--){
		Barr[i] = (b/10);
		b /= 10;
	}
	//최대
	for(int i = 0 ; i < a_cnt ; i++){
		if(Aarr[i] == 5) Aarr[i] = 6;
		if(Barr[i] == 5) Barr[i] = 6;
	}
	for(int i = 0 ; i < a_cnt ; i++{
		Aarr[i] = 
	}
	//최소
	for(int i = 0 ; i < a_cnt ; i++){
		if(Aarr[i] == 6) Aarr[i] = 5;
		if(Barr[i] == 6) Barr[i] = 5;
	}
}