#include <iostream>

using namespace std;

int main(){
	int sequenceLength;
	cin >> sequenceLength;
	int arr[sequenceLength];
	int dp[1001] = {};
	int max = 0;
	for(int i = 0 ; i < sequenceLength ; i++){
		cin >> arr[i];
	}
	for(int i = 0 ; i < sequenceLength ; i++){
		if(dp[i] == 0) dp[i] = 1;
		for(int j = 0 ; j < i ; j++){
			if(arr[i] > arr[j]){
				if(dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	for(int i = 0 ; i < sequenceLength ; i++){
		if(max < dp[i]) max = dp[i];
	}
	cout << max;
	return 0;
}