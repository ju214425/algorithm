#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool func(int number, int base){
	vector<int> v1, v2;
	while(number != 0){
		v1.push_back(number % base);
		v2.push_back(number % base);
		number /= base;
	}

	reverse(v2.begin(), v2.end());

	if(v1 == v2) return true;
	return false;
}

int main(){
	int t, n;
	cin >> t;
	bool ans;

	while(t--){
		cin >> n;
		ans = false;
		for(int i = 2 ; i <= 64 ; i++){
			if(func(n, i)){
				ans = true;
				break;
			}
		}
		if(ans) cout << 1 << endl;
		else{
			cout << 0 << endl;
		}
	}
}