#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int sum = 0;
	cin >> n;

	vector<int> v(n+1);
	for(int i = 1 ; i <= n ; i++){
		cin >> v[i];
	}

	sort(v.begin()+1, v.end());

	for(int i = 1 ; i <= n ; i++){
		sum += v[i];
		if(sum < (i * (i - 1)) / 2){
			cout << -1 << "\n";
			return 0;
		}
	}
	if(sum != n * (n-1) / 2)
		cout << -1 <<"\n";
	else{
		cout << 1 << "\n";
	}
	return 0;
}