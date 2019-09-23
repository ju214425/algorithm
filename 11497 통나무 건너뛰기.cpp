#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		vector<int> v(n), t;

		for(int i = 0 ; i < n ; i++){
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		// print(v);
		for(int i = 0 ; i < n ; i += 2){
			t.push_back(v[i]);
		}
		
		if(n % 2 == 0){
			for(int i = n-1 ; i >= 0 ; i -= 2){
				t.push_back(v[i]);
			}
		}
		else{
			for(int i = n-2 ; i >= 0 ; i -= 2){
				t.push_back(v[i]);
			}
		}

		int max_val = -1;
		for(int i = 1 ; i < n ; i++){
			max_val = max(abs(t[i] - t[i-1]), max_val);
		}
		max_val = max(max_val, abs(t[n-1] - t[0]));

		cout << max_val << "\n";
	}
}