// #include <iostream>

// using namespace std;

// int max(int num1, int num2){
// 	return num1 > num2 ? num1 : num2;
// }

// int main(){
// 	int numberOfTests;
// 	cin >> numberOfTests;
// 	int answerArr[numberOfTests + 1];
// 	for(int i = 1 ; i <= numberOfTests ; i++){
// 		int length;
// 		cin >> length;
// 		int arr[length + 1][2];
// 		int dp[length + 1];
// 		int temp = 0;
// 		for(int j = 0 ; j < 2 ; j++){
// 			for(int k = 1 ; k <= length ; k++){
// 				cin >> arr[k][j];
// 			}
// 		}
// 		dp[0] = 0;
// 		dp[1] = max(arr[1][0], arr[1][1]);
// 		dp[2] = max(arr[1][0] + arr[2][1], arr[1][1] + arr[2][0]);
// 		for(int j = 3 ; j <= length ; j++){
// 			int cur = max(arr[j][0], arr[j][1]);
// 			int check = 0;
// 			if(dp[j-1] == dp[j-2] + arr[j-1][0]){
// 				check = arr[j][1];
// 			}
// 			else{
// 				check = arr[j][0];
// 			}
// 			dp[j] = max(dp[j-2] + cur, dp[j-1] + check);
// 		}
// 		answerArr[i] = dp[length];
// 	}
// 	for(int i = 1 ; i <= numberOfTests ; i++){
// 		cout << answerArr[i] << endl;
// 	}

// 	return 0;
// }

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005][2];
int  dp[100005][2];

int main(){
	int t, answer;
	scanf("%d", &t);
	for(int i = 0 ; i < t ; i++){
		int n;
		scanf("%d", &n);
		for(int j = 0 ; j < n ; j++){
			scanf("%d", &arr[j][0]);
		}
		for(int j = 0 ; j < n ; j++){
			scanf("%d", &arr[j][1]);	
		}

		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = arr[0][1] + arr[1][0];
		dp[1][1] = arr[0][0] + arr[1][1];

		for(int j = 2 ; j < n ; j++){
			dp[j][0] = arr[j][0] + max(dp[j-1][1], dp[j-2][1]);
			dp[j][1] = arr[j][1] + max(dp[j-1][0], dp[j-2][0]);
		}
		answer = max(dp[n-1][0], dp[n-1][1]);
		printf("%d\n", answer);

	}
}