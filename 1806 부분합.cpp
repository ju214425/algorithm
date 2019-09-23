#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int front = 0, back = 0;
	int sum = 0;
	int cnt = 0;
	int len = 0x7fffffff;
	cin >> n >> m;

	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}

	while(true){
		if(sum >= m){
			sum -= v[front++];
		}
		else if(back == n) break;
		else{
			sum += v[back++];
		}
		if(sum >= m){
			cnt++;
			len = min(len, back - front);
		}
	}

	if(cnt == 0){
		cout << 0 << "\n";
	}
	else{
		cout << len << "\n";
	}
}