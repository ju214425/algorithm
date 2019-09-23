#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a, b, n, w;
	int cnt = 0;
	cin >> a >> b >> n >> w;

	vector<int> v; 
	for(int i = 1 ; i < n ; i++){
		if(i * a + (n - i) * b == w){
			v.push_back(i);
			cnt++;
		}
	}

	if(cnt != 1){
		cout << -1;
	}
	else{
		cout << v[0] << " " << n - v[0];
	}
}