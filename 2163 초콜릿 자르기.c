#include <stdio.h>
#define max 10
int dp[301][301];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1 ; i <= 300 ; i++){
		for(int j = 1 ; j <= 300 ; j++){
			dp[i][1] = i-1;
			dp[1][j] = j-1;
		}
	}
	for(int i = 2 ; i <= 300 ; i++){
		for(int j = 2; j <= 300 ; j++){
			if(i % 2 != 0 && j % 2 != 0){
				dp[i][j] = dp[i][j-1] + dp[i][1] + 1;
			}
			else if(i % 2 == 0 && j % 2 != 0){
				dp[i][j] = 2 * dp[i/2][j] + 1;
			}
			else if(i % 2 != 0 && j % 2 == 0){
				dp[i][j] = 2 * dp[i][j/2] + 1;
			}
			else if(i % 2 == 0 && j % 2 == 0){
				dp[i][j] = 2 * dp[i][j/2] + 1;
			}
		}
	}

	printf("%d", dp[n][m]);
}