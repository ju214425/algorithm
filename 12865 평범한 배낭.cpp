#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > v;
	for(int i = 0 ; i < k ; i++){
		cin >> v[i].first >> v[i].second;
	}
	
}