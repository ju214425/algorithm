#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000

int dp[5005][2];

int main(){
	int ans = 0;
	string pw;
	cin >> pw;

	vector<int> v;
	
	int cnt = 0;
	for(int i = 0 ; i < pw.size() ; i++){
		if(pw[i] - 48 == 0)
	}

	dp[0][0] = 0;
	dp[0][1] = 1;

	for(int i = 1 ; i < v.size() ; i++){
		if(0 < v[i-1] * 10 + v[i] and v[i-1] * 10 + v[i] <= 26){ // 연달아 가능
			dp[i][0] = dp[i-1][1];
		}
		else{
			dp[i][0] = 0;
		}
		dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
	}
	if(pw[0] == 48) cout << 0;
	else{
		cout << (dp[v.size()-1][0] + dp[v.size()-1][1]) % MOD;
	}
}