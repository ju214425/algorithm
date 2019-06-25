#include <stdio.h>

long long dp[70];
int arr[70];
int main(){
	int numberOfTest;
	scanf("%d", &numberOfTest);
	for(int i = 0 ; i < numberOfTest ; i++){
		scanf("%d", &arr[i]);
	}
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i < 68 ; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
	}
	for(int i = 0 ; i < numberOfTest ; i++){
		printf("%lli\n", dp[arr[i]]);
	}
}