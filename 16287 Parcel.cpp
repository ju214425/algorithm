#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int w, n;
	cin >> w >> n;

	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	
}