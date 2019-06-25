#include <stdio.h>

int dp[11][21];

int main(){
	int number;
	scanf("%d", &number);
	for(int i = 1 ; i < 11 ; i++){
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	dp[1][2] = 1;
	for(int i = 2 ; i < 11 ; i++){
		for(int j = 2 ; j < 21 ; j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2];
		}
	}
	int result = 0;
	for(int i = 1 ; i <= 2 * number ; i = i + 3){
		result += (dp[number - 1][i] + dp[number - 1][i + 1]);
	}
	printf("%d", result);

}