#include <cstdio>

#define MOD 9901

using namespace std;

int dp[100001];

int main(){
	int n;
	scanf("%d", &n);
	dp[1] = 3;
	dp[2] = 7;
	for(int i = 3 ; i <= n ; i++){
		dp[i] = (2 * dp[i-1] + dp[i-2]) % MOD;
	}

	printf("%d", dp[n]);
}