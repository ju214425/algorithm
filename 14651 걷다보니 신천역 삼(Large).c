#include <stdio.h>

long int dp[33350][33350];

int main(){
	int number;
	scanf("%d", &number);
	for(int i = 1 ; i < 33350 ; i++){
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	dp[1][2] = 1;
	for(int i = 2 ; i < 33350 ; i++){
		for(int j = 2 ; j < 33350 ; j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2];
		}
	}
	long int result = 0;
	for(int i = 1 ; i <= 2 * number ; i = i + 3){
		result += (dp[number - 1][i] + dp[number - 1][i + 1]);
		result %= 1000000009;
	}
	printf("%li", result % 1000000009);

}