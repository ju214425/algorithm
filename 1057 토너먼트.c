#include <stdio.h>

int times(int number){
	int value = 1;
	for(int i = 0 ; i < number ; i++){
		value *= 2;
	}
	return value;
}

int main(){
	int numberOfPeople;
	int Kim;
	int Lim;
	scanf("%d %d %d", &numberOfPeople, &Kim, &Lim);
	int greater = Kim > Lim	? Kim : Lim;
	int smaller = Kim < Lim	? Kim : Lim;
	int result;
	int greater_s;
	int smaller_s;
	int check;
	int arr[18] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4196,8192,16384,32768,65536,100000};
	for(int i = 0 ; i < 16 ; i++){
		if(greater > arr[i] && arr[i+1] >= greater){
			greater_s = i+1;
		}
		if(smaller > arr[i] && arr[i+1] >= smaller){
			smaller_s = i+1;
			check = i+1;
		}
	}
	if(smaller_s == greater_s){
		while(smaller_s != greater_s){
			greater -= times(check);
			smaller -= times(check);
			for(int i = 0 ; i < 16 ; i++){
				if(greater > arr[i] && arr[i+1] >= greater){
					greater_s = i+1;
				}
				if(smaller > arr[i] && arr[i+1] >= smaller){
					smaller_s = i+1;
					check = i+1;
				}
			}
		}
	}
	else{
		result = greater_s;
	}
	printf("%d", result);

}