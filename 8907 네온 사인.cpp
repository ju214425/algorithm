#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, color, cnt = 0;
	cin >> t;
	while(t--){
		cin >> n;
		cnt = 0;
		for(int i = 0 ; i < n ; i++){
			arr[i] = 0;
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = i+1 ; j < n ; j++){
				cin >> color;
				arr[i] += color;
				arr[j] += color;
			}
		}
		for(int i = 0 ; i < n ; i++){
			cnt += arr[i] * (n-1-arr[i]);
		}
		cout << n*(n-1)*(n-2)/6 - cnt/2 << "\n";
		
	}
}