#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	cin >> m;
	
	for(int i = 0 ; i < m ; i++){
		int number, start = 0, end = n-1, mid;
		bool ans = false;
		cin >> number;
		while(end >= start){
			mid = (start + end) / 2;
			if(v[mid] == number){
				ans = true;
				break;
			}
			else if(v[mid] > number){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}
		if(ans) cout << "1\n";
		else cout << "0\n";
	}
}