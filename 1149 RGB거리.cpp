#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

using namespace std;

int arr[1005][3];
int dp[1005][3];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 0 ; j < 3 ; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for(int i = 1 ; i <= n ; i++) {
		for(int j = 0 ; j < 3 ; j++) {
			if(j == 0) dp[i][j] = arr[i][j] + min(dp[i-1][1], dp[i-1][2]);
			else if(j == 1) dp[i][j] = arr[i][j] + min(dp[i-1][0], dp[i-1][2]);
			else dp[i][j] = arr[i][j] + min(dp[i-1][0], dp[i-1][1]);
		}
	}

	int answer = INF;
	for(int i = 0 ; i < 3 ; i++) {
		if(dp[n][i] < answer) answer = dp[n][i];
	}
	printf("%d", answer);
}
