#include <cstdio>

#define DIV 1000000000

int dp[101][11] = {};

int main(){
	int n, answer = 0;
	scanf("%d", &n);

	for(int i = 0 ; i < 10 ; i++) {
		dp[1][i] = 1;
	}

	for(int i = 2 ; i <= n ; i++) {
		for(int j = 0 ; j < 10 ; j++){
			if(j == 0) dp[i][j] = dp[i-1][1];
			else if(j == 9) dp[i][j] = dp[i-1][8];
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % DIV;
		}
	}

	for(int i = 1 ; i < 10 ; i++) {
		answer = (answer + dp[n][i]) % DIV;
	}

	printf("%d\n", answer % DIV);
}