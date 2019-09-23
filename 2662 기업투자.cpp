#include <cstdio>
#include <vector>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int dp[n][m];
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			scanf("%d", &dp[i][j]);
		}
	}
}