#include <iostream>

using namespace std;

typedef long long ll;

ll dp[110];

int main(){
	int l, k;
	cin >> l >> k;

	ll sum = 0;

	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2 ; i < k ; i++){
		dp[i] = dp[i-2];
	}
	dp[k] = 1 + dp[k-2];
	for(int i = k+1 ; i <= l ; i++){
		dp[i] = dp[i-2] + dp[i-k-1];
	}
	for(int i = 0 ; i <= l ; i++){
		sum += dp[i];
	}

	cout << sum;
}