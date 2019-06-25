#include <stdio.h>

int arr[1005];
int dp[1005];

int main(){
	int sizeOfSequence;
	scanf("%d", &sizeOfSequence);
	for(int i = 0 ; i < sizeOfSequence ; i++){
		scanf("%d", &arr[i]);
	}
	dp[0] = 1;
	int min = arr[0];
	int max = dp[0];
	for(int i = 0 ; i < sizeOfSequence - 1 ; i++){
		if(arr[i] > arr[i+1]) {
			if(min > arr[i+1]){
				dp[i+1] = dp[i] + 1;
				max = dp[i] + 1;
				min = arr[i+1];
			}
			else dp[i+1] = max;
		}
		else dp[i+1] = dp[i];
	}

	printf("%d",dp[sizeOfSequence - 1]);
}