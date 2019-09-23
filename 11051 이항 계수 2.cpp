#include <cstdio>

#define MOD 10007

int arr[1001][1001];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; i++){
		arr[i][0] = arr[i][i] = 1;
	}
	for(int i = 2 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % MOD;
		}
	}

	printf("%d", arr[n][k]);
}