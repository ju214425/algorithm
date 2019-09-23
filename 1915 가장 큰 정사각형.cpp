#include <iostream>

using namespace std;

int arr[1002][1002];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int max_val = 0;
	string str;

	for(int i = 0 ; i < n ; i++){
		cin >> str;
		for(int j = 0 ; j < m ; j++){
			arr[i][j] = str[j] - 48;
			max_val = max(max_val, arr[i][j]);
		}
	}


	for(int i = 1 ; i < n ; i++){
		for(int j = 1 ; j < m ; j++){
			if(arr[i][j] == 1){
				int near_min = min(arr[i-1][j], min(arr[i-1][j-1], arr[i][j-1]));
				if(near_min != 0){
					arr[i][j] = near_min + 1;
					max_val = max(max_val, arr[i][j]);
				}
			}
		}
	}

	cout << max_val * max_val;
}